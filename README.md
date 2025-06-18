# 🎬 Movie Recommendation System: ALS vs SGD Matrix Factorization

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Dataset](https://img.shields.io/badge/Dataset-MovieLens%20100K-orange.svg)](https://grouplens.org/datasets/movielens/100k/)

A comprehensive **C++ implementation** and **comparative study** of two matrix factorization algorithms for movie recommendation systems: **Alternating Least Squares (ALS)** and **Stochastic Gradient Descent (SGD)**. This project provides detailed performance analysis, evaluation metrics, architectural overview, and production-oriented insights.

---

## 🌟 Key Highlights

- **Superior ALS Performance**: 18.45% RMSE improvement over SGD
- **Production-Ready C++ Code**: Clean, optimized, modern C++
- **Detailed Evaluation**: Accuracy, convergence, and scalability comparisons
- **Research-Based**: Based on academic methodology and experimentation
- **Real Dataset**: Uses the MovieLens 100K benchmark dataset

---

## 📊 Performance Results

| Algorithm | Final RMSE | Final MAE | Improvement | Convergence |
|-----------|------------|-----------|-------------|-------------|
| **ALS**   | **0.6849** | **0.5263** | **18.45%**  | Fast (10 iterations) |
| **SGD**   | 0.8357     | 0.6667     | 12.72%      | Gradual (30+ iterations) |

### 🔍 Convergence Patterns

- **ALS**: Rapid initial improvement; plateaus after ~10 iterations
- **SGD**: Consistent, gradual improvement throughout training

---

## 🧠 What is a Recommender System?

A **recommender system** is a machine learning model that predicts and suggests items (movies, music, products, etc.) a user might like, based on past interactions.

### 🎯 Why Use Recommenders?

- **Personalization**: Tailor content to individual users
- **Discovery**: Help users explore new items
- **Engagement**: Increase time spent on platform
- **Conversion**: Boost sales or usage (Netflix, Amazon, Spotify)
- **User Experience**: Make platforms more intuitive and helpful

### 💡 Real-World Examples

- **Netflix**: “Recommended for you”
- **Amazon**: “Customers also bought…”
- **Spotify**: “Discover Weekly”
- **YouTube**: “Suggested Videos”

### ⚠️ The Sparsity Problem

Users only interact with a tiny fraction of items:

- Netflix users rate <1% of all titles
- Amazon shoppers buy only a few of millions of products
- Results in >95% of the user-item matrix being empty

---

## 🔢 What is Matrix Factorization?

Matrix factorization is a mathematical technique that breaks a large, sparse matrix into two smaller, dense ones capturing **latent features** of users and items.

### 🎭 Conceptual Example

Imagine each movie and user described by hidden features:

**Movie latent vector**:
- Action: 0.8
- Romance: 0.2
- Comedy: 0.6

**User preference vector**:
- Likes action: 0.9
- Likes romance: 0.1
- Likes comedy: 0.7

**Predicted Rating** = dot(user, movie) = (0.9×0.8) + (0.1×0.2) + (0.7×0.6) = 1.16

### 🧮 Mathematical Representation

Original Matrix (R) ≈ User Matrix (U) × Item Matrix (Vᵀ)
[943 × 1682] = [943 × k] × [k × 1682]

yaml
Copiar
Editar

Where `k` is the number of latent dimensions.

---

## 🧠 Algorithms Implemented

### 🔸 Alternating Least Squares (ALS)

**How It Works**:

1. Initialize U and V randomly
2. Fix V and solve for U using least squares
3. Fix U and solve for V
4. Repeat until convergence

**Mathematical Form**:

U_i = (VᵀV + λI)⁻¹ * Vᵀ * R_i
V_j = (UᵀU + λI)⁻¹ * Uᵀ * R_j
Best for:

Offline batch processing

High-accuracy systems

Scenarios where parallel processing is possible

---

## 🧠 Algorithms Implemented

### 🔹 Stochastic Gradient Descent (SGD)


How It Works:

Initialize U and V with small values

For each known rating:

Compute error: e = rating - prediction

Update U and V using gradient descent

Repeat over many iterations

Pseudocode:

cpp
Copiar
Editar
for each (i, j, rating) in data:
    error = rating - dot(U[i], V[j])
    U[i] += η * (error * V[j] - λ * U[i])
    V[j] += η * (error * U[i] - λ * V[j])
Best for:

Online/streaming systems

Low-memory environments

Simple implementations

🏗️ Project Architecture
css
Copiar
Editar
📦 movie-recommendation-cpp/
├── data/
│   └── ratings.csv
├── include/
│   ├── ALS.hpp
│   ├── SGD.hpp
│   ├── MatrixFactorization.hpp
│   └── utils.hpp
├── src/
│   ├── ALS.cpp
│   ├── SGD.cpp
│   ├── main.cpp
│   └── utils.cpp
├── results/
│   ├── performance_metrics.txt
│   └── convergence_data.csv
├── plots/
│   ├── als_convergence.png
│   └── sgd_convergence.png
├── Makefile
└── README.md
🚀 Quick Start
Requirements
C++17 compatible compiler

Make

Git

Setup
bash
Copiar
Editar
git clone https://github.com/yourusername/movie-recommendation-cpp.git
cd movie-recommendation-cpp
make
./recommender
⚙️ Hyperparameter Tuning
You can adjust the following in main.cpp:

Parameter	Description	Default
k	Latent factors	50
lambda	Regularization	0.1
learning_rate	SGD learning rate	0.01
iterations	Number of training iterations	30

📊 Evaluation Metrics
📏 RMSE (Root Mean Squared Error)
Penalizes large errors

Sensitive to outliers

Lower = better

📐 MAE (Mean Absolute Error)
Measures average absolute difference

More robust to outliers

Lower = better

In our results:

Metric	ALS	SGD
RMSE	0.6849	0.8357
MAE	0.5263	0.6667

🔬 Research Findings
When to Use ALS?
You have batch/offline training time

You need high accuracy

You can parallelize computation

When to Use SGD?
You need online or incremental learning

You have limited memory or compute

You prefer simpler implementation

📚 Dataset Information
Dataset: MovieLens 100K

943 users, 1,682 movies

100,000 total ratings

Rating scale: 1 to 5 stars

Format: user_id, item_id, rating

👨‍💻 Author
Andres Alexander Basantes Balcazar
School of Mathematical and Computational Sciences
Universidad Yachay Tech – Ecuador
📧 andres.basantes@yachaytech.edu.ec
