from __future__ import print_function

import torch

# 用 torch 来实现两层神经网络模型
# h = w1*x
# a = max(0,h)
# y_pred = w2a
# loss = (y_pred-y)^2

# 64条训练样本，样本特征维度1024，隐层大小size=100，输出层类别10类
N, Din, H, Dout = 64, 1024, 100, 10
x = torch.randn(N, Din)
y = torch.randn(N, Dout)
w1 = torch.randn(Din, H)
w2 = torch.randn(H, Dout)

for iter in range(0, 1000):
    # forward pass
    h = x.mm(w1)  # (N,Din) * (Din, H) = (N,H)
    h_relu = h.clamp(min=0)  # (N,H)
    y_pred = h_relu.mm(w2)  # (N,H) * (H,Dout) = (N,Dout)

    # compute loss
    loss = (y_pred - y).pow(2).sum().item()
    print(iter, loss)

    # backward pass
    grad_y_pred = 2.0 * (y_pred - y)
    grad_w2 = h_relu.t().mm(grad_y_pred)  # 矩阵转置 = 矩阵^(-1)，仅当某些情况
    grad_h_relu = grad_y_pred.mm(w2.t())
    grad_h = grad_h_relu.clone()
    grad_h[h < 0] = 0
    grad_w1 = x.t().mm(grad_h)

    # update weights
    learning_rate = 1e-6
    w1 -= learning_rate * grad_w1
    w2 -= learning_rate * grad_w2
