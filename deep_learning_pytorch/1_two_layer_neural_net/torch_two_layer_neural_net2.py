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
w1 = torch.randn(Din, H, requires_grad=True)
w2 = torch.randn(H, Dout, requires_grad=True)

for iter in range(0, 1000):
    # forward pass
    y_pred = x.mm(w1).clamp(min=0).mm(w2)  # N * Dout
    # compute loss
    loss = (y_pred - y).pow(2).sum()
    print(iter, loss.item())

    # backward pass
    loss.backward()
    # update weights
    learning_rate = 1e-6
    with torch.no_grad():
        w1 -= learning_rate * w1.grad
        w2 -= learning_rate * w2.grad
        w1.grad.zero_()
        w2.grad.zero_()
