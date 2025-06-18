# FINAL-PROJECT

# 📽️ Movie Recommendation System using ALS and SGD (C++)

This project implements and compares two popular matrix factorization algorithms — **Alternating Least Squares (ALS)** and **Stochastic Gradient Descent (SGD)** — to build a movie recommendation system. The code is written in modern C++ and tested on the [MovieLens 100K](https://grouplens.org/datasets/movielens/100k/) dataset.

---

## 📚 What is a Recommender System?

A **recommender system** is a machine learning-based tool that predicts user preferences and suggests items (such as movies, music, or products). It is a core technology behind platforms like Netflix, Amazon, and Spotify.

Due to the sparsity of real-world user-item interactions (most users rate only a small fraction of items), **matrix factorization** is widely used to infer missing ratings by learning latent factors for users and items.

---

## 🧠 Algorithms Implemented

### 🔸 Alternating Least Squares (ALS)

ALS alternates between fixing the user matrix **U** and solving for the item matrix **V**, and vice versa. Each step involves solving a regularized least squares problem.

**Pros**:
- Fast convergence
- Parallelizable
- Good for batch processing

**Cons**:
- Higher per-iteration computational cost (matrix inversions)
- Requires more memory

### 🔹 Stochastic Gradient Descent (SGD)

SGD updates the user and item matrices iteratively using gradient descent on observed ratings.

**Pros**:
- Simple to implement
- Low memory usage
- Works well in online settings

**Cons**:
- Slower convergence
- Sensitive to learning rate and hyperparameters

---

## 🧮 Evaluation Metrics

We evaluate both algorithms using the following metrics:

| Metric | Description |
|--------|-------------|
| **RMSE** (Root Mean Squared Error) | Penalizes large errors more strongly. Lower RMSE indicates better accuracy. |
| **MAE** (Mean Absolute Error) | Measures average magnitude of prediction errors. Lower is better. |

**Final results (MovieLens 100K):**

| Algorithm | RMSE  | MAE   |
|-----------|-------|--------|
| ALS       | 0.6849 | 0.5263 |
| SGD       | 0.8357 | 0.6667 |

---

## 🧱 Project Architecture


