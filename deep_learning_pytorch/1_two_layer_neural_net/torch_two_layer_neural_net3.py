from __future__ import print_function

import torch
import torch.nn as nn

# 用 torch 来实现两层神经网络模型
# h = w1*x
# a = max(0,h)不至于自己老年痴呆，
# y_pred = w2a
# loss = (y_pred-y)^2

# 64条训练样本，样本特征维度1024，隐层大小size=100，输出层类别10类
N, Din, H, Dout = 64, 1024, 100, 10
x = torch.randn(N, Din)
y = torch.randn(N, Dout)
model = nn.Sequential(
    nn.Linear(Din, H),
    nn.ReLU(),
    nn.Linear(H, Dout)
)
nn.init.normal_(model[0].weight)
nn.init.normal_(model[2].weight)
loss_fn = nn.MSELoss(reduction='sum')
for iter in range(0, 1000):
    # forward pass
    y_pred = model(x)
    # compute loss
    loss = loss_fn(y_pred, y)
    print(iter, loss.item())
    # backward pass
    loss.backward()
    # update weights
    learning_rate = 1e-6
    with torch.no_grad():
        for param in model.parameters():
            param -= learning_rate * param.grad
            param.grad.zero_()
