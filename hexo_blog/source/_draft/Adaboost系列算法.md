---
layout: post
title: "Adaboost、Adaboost.MH和MP-Boost算法原理和对比"
date: 2022-05-14 16:15
tag:
  - Classification
  - Adaboost
  - Adaboost.MH
  - MP-Boost
  - 集成学习
  - Ensemble Learning
categories: ML
---

## 1.基本介绍

Adaboost可以认为是机器学习中一个集成学习的算法框架，主要集中于解决二分类问题；而Adaboost.MH不仅仅可以解决多分类问题，还可以解决一个样本有多个标签的问题，比如说一个篇新闻既属于体育类又属于篮球类，那么这篇新闻可以同时打上两个标签（新闻和篮球），所以Adaboost.MH可以解决Multi-Label Multi-Class问题；MP-Boost算法和Adaboost.MH类似，是Adaboost.MH一个优化版，可以大大减少模型的训练时长，且对于非高频类别样本，MP-Boost比Adaboost.MH模型效果更好。下面咱们来详细介绍这些算法的原理和现实。
在对话系统中，经常会出现一个句子（可以看做是“一个单轮对话”）在没有上下文的情况，无法区分它到底属于哪个场景，如下图所示，无法区分一句话“从融科资讯中心到盈都大厦”到底属于打车的场景还是跑腿的场景。如果考虑对话的场景的话，用户上文中说了“帮我打一辆车”，那么我们对该句话“从融科资讯中心到盈都大厦”在打车场景下的标签得分应该是最高的。从对话语料统计的角度来考虑，也许打车场景的得分是0.90，跑腿的场景的得分是0.05，其他的场景得分是0.05。这样，Adaboost.MH和MP-Boost算法正好可以用来解决对话中领域(domain)归属问题。

<image style="border:0px" width="1500" highth="800" src="/images/不考虑上下文的场景的对话的例子.jpg"/>


## 2.AdaBoost 算法流程

给定一个训练数据集T

``` bash
$ hexo new "My New Post"
```

## 3.Adaboost.MH 算法流程
给定一个训练数据集T

``` bash
$ hexo new "My New Post"
```


## 4.MP-Boost 算法流程
给定一个训练数据集T

``` bash
$ hexo new "My New Post"
```

## 5.总结
给定一个训练数据集T

``` bash
$ hexo new "My New Post"
```

## 6.参考文献

[1] <a href="http://link.springer.com/article/10.1023%2FA%3A1007649029923">BoosTexter:A Boosting-based System for Text Categorization</a>
[2] <a href="http://blog.csdn.net/v_july_v/article/details/40718799">AdaBoost 算法的原理与推导</a>
