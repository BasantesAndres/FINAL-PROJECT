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


Offline batch processing

High-accuracy systems

Scenarios where parallel processing is possible


**✅ Advantages:**
- **Fast Convergence**: Achieves optimal performance in fewer iterations
- **Parallelizable**: User/item updates can be computed independently
- **Stable**: Direct analytical optimization prevents gradient instability
- **Batch Processing**: Ideal for offline recommendation systems

**❌ Disadvantages:**
- **Memory Intensive**: Requires matrix inversions and more storage
- **Computational Cost**: O(k³ + nk²) complexity per iteration
- **Batch Only**: Not suitable for real-time online learning



---

## 🧠 Algorithms Implemented

### 🔹 Stochastic Gradient Descent (SGD)
SGD updates factors incrementally using gradient-based optimization for each observed rating.


How It Works:

Initialize U and V with small values

For each known rating:

Compute error: e = rating - prediction

Update U and V using gradient descent

Repeat over many iterations

Best for:

Online/streaming systems

Low-memory environments

Simple implementations

**✅ Advantages:**
- **Memory Efficient**: Low memory footprint with O(nk) complexity
- **Online Learning**: Supports real-time model updates
- **Simple Implementation**: Straightforward gradient-based approach
- **Scalable**: Works well with streaming data

**❌ Disadvantages:**
- **Slower Convergence**: Requires more iterations for comparable accuracy
- **Parameter Sensitive**: Highly dependent on learning rate tuning
- **Sequential Processing**: Limited parallelization opportunities


---

## 🏗️ Project Architecture

```
📦 movie-recommendation-cpp/
├── 📁 data/                 
│   └── 📄 ratings.csv            # Input dataset (movie ratings)
├── 📁 eigen/                    
│   └── 📄 [Eigen library]        # Eigen library used for algebraic operations
├── 📄 als.cpp                      # ALS (Alternating Least Squares) implementation
├── 📄 als.h                      # ALS (Alternating Least Squares) header
├── 📄 als_metrics              # Evaluation metrics from ALS
├── 📄 als_time                 # ALS training time
├── 📄 extensions.cpp              # Additional extensions or configuration files
├── 📄 extensions.h               # Additional header
├── 📄 main.cpp                     # Main file that runs the program
├── 📄 matrix_loader.cpp            # Loads matrix-format data
├── 📄 matrix_loader.h            # Loads matrix-format data header
├── 📄 metrics.cpp                  # Metric evaluation (e.g., RMSE, MAE)
├── 📄 metrics.h                  # Metric evaluation (e.g., RMSE, MAE) header
├── 📄 recommend                # Core logic of the recommendation system
├── 📄 sgd,cpp                      # SGD (Stochastic Gradient Descent) implementation
├── 📄 sgd.h                      # SGD (Stochastic Gradient Descent) header
├── 📄 sgd_metrics              # Evaluation metrics from SGD
├── 📄 sgd_time                 # SGD training time
├── 📄 top5                    # Output with top 5 movie recommendations
├── 📄 README                   # Project documentation

```

---

## ⚙️ Configuration & Hyperparameters

Customize the algorithms by modifying these parameters in `main.cpp`:

| Parameter | Description | Default | Range |
|-----------|-------------|---------|-------|
| `k` | Number of latent factors | 50 | 10-200 |
| `lambda` | Regularization parameter | 0.1 | 0.001-1.0 |
| `learning_rate` | SGD learning rate | 0.01 | 0.001-0.1 |
| `max_iterations` | Training iterations | 30 | 10-100 |
| `train_ratio` | Training/test split | 0.8 | 0.7-0.9 |


---

## 📈 Evaluation Metrics

### Root Mean Squared Error (RMSE)
Measures the square root of the average squared differences between predicted and actual ratings.

```cpp
RMSE = sqrt(Σ(predicted - actual)² / n)
```

### Mean Absolute Error (MAE)
Calculates the average absolute differences between predictions and ground truth.

```cpp
MAE = Σ|predicted - actual| / n
```

**Lower values indicate better performance for both metrics.**

---

## 🔬 Research Findings & Insights

### Algorithm Selection Guidelines

**Choose ALS when:**
- ✅ **Batch processing** is acceptable
- ✅ **High accuracy** is the primary requirement
- ✅ **Computational resources** are available
- ✅ **Parallel processing** can be leveraged
- ✅ **Offline recommendations** are sufficient

**Choose SGD when:**
- ✅ **Online learning** is required
- ✅ **Memory constraints** are significant  
- ✅ **Real-time updates** are necessary
- ✅ **Simple implementation** is preferred
- ✅ **Streaming data** scenarios

### Performance Analysis Summary

| Aspect | ALS | SGD |
|--------|-----|-----|
| **Accuracy** | Superior (18.45% better RMSE) | Good baseline performance |
| **Convergence** | Fast (10 iterations) | Gradual (30+ iterations) |
| **Memory Usage** | Higher | Lower |
| **Parallelization** | Excellent | Limited |
| **Implementation** | Complex (matrix ops) | Simple (gradient updates) |
| **Use Case** | Batch/offline systems | Online/streaming systems |

---

## 📚 Dataset Information

This project uses the **MovieLens 100K** dataset:
- **100,000 ratings** from 943 users on 1,682 movies
- **Rating scale**: 1-5 stars
- **Sparsity**: ~95% (typical of real-world scenarios)
- **Format**: CSV with columns (user_id, item_id, rating)

The dataset simulates a real-world scenario similar to Netflix, where the vast majority of user-item pairs are unobserved, making accurate prediction challenging and practically relevant.

---

---

## 👨‍💻 Author

**Andres Alexander Basantes Balcazar**  
🎓 School of Mathematical and Computational Sciences  
🏫 Universidad Yachay Tech, Ecuador  
📧 [andres.basantes@yachaytech.edu.ec](mailto:andres.basantes@yachaytech.edu.ec)  

---
