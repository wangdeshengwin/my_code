from __future__ import print_function

import numpy as np

# 用 numpy 来实现两层神经网络模型
# h = w1*x
# a = max(0,h)
# y_pred = w2a
# loss = (y_pred-y)^2

# 64条训练样本，样本特征维度1024，隐层大小size=100，输出层类别10类
N, Din, H, Dout = 64, 1024, 100, 10
x = np.random.randn(N, Din)
y = np.random.randn(N, Dout)
w1 = np.random.randn(Din, H)
w2 = np.random.randn(H, Dout)

for iter in range(0, 1000):
    # forward pass
    h = x.dot(w1)  # (N,Din) * (Din, H) = (N,H)
    h_relu = np.maximum(0, h)  # (N,H)
    y_pred = h_relu.dot(w2)  # (N,H) * (H,Dout) = (N,Dout)

    # compute loss
    loss = np.square(y_pred - y).sum()
    print(iter, loss)

    # backward pass
    grad_y_pred = 2.0 * (y_pred - y)
    grad_w2 = h_relu.T.dot(grad_y_pred)  # 矩阵转置 = 矩阵^(-1)，仅当某些情况
    grad_h_relu = grad_y_pred.dot(w2.T)
    grad_h = grad_h_relu.copy()
    grad_h[h < 0] = 0
    grad_w1 = x.T.dot(grad_h)

    # update weights
    learning_rate = 1e-6
    w1 -= learning_rate * grad_w1
    w2 -= learning_rate * grad_w2
