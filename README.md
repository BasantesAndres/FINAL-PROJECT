# 🎬 Movie Recommendation System: ALS vs SGD Matrix Factorization

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Dataset](https://img.shields.io/badge/Dataset-MovieLens%20100K-orange.svg)](https://grouplens.org/datasets/movielens/100k/)

A comprehensive **C++ implementation** and **comparative study** of two popular matrix factorization algorithms for building movie recommendation systems. This project implements both **Alternating Least Squares (ALS)** and **Stochastic Gradient Descent (SGD)** algorithms from scratch, providing detailed performance analysis and practical insights for production systems.

## 🌟 Key Highlights

- **Superior ALS Performance**: 18.45% RMSE improvement over SGD
- **Production-Ready C++ Code**: Optimized implementations with modern C++ features
- **Comprehensive Analysis**: Detailed convergence patterns and computational trade-offs
- **Research-Backed**: Based on academic research with rigorous experimental methodology
- **Real-World Dataset**: Tested on MovieLens 100K with 100,000 ratings from 943 users

---

## 📊 Performance Results

Our experimental results demonstrate clear performance differences between the algorithms:

| Algorithm | Final RMSE | Final MAE | Improvement | Convergence Speed |
|-----------|------------|-----------|-------------|-------------------|
| **ALS**   | **0.6849** | **0.5263** | **18.45%** | Fast (10 iterations) |
| **SGD**   | 0.8357     | 0.6667     | 12.72%      | Gradual (30+ iterations) |

### 📈 Convergence Patterns
- **ALS**: Rapid initial improvement with stabilization after ~10 iterations
- **SGD**: Consistent gradual improvement throughout training process

---

## 🧠 Algorithm Deep Dive

### 🔸 Alternating Least Squares (ALS)
ALS alternates between fixing user factors and solving for item factors using closed-form least squares solutions.

```cpp
// Simplified ALS update formula
U_i = (V^T * V + λI)^(-1) * V^T * R_i
V_j = (U^T * U + λI)^(-1) * U^T * R_j
```

**✅ Advantages:**
- **Fast Convergence**: Achieves optimal performance in fewer iterations
- **Parallelizable**: User/item updates can be computed independently
- **Stable**: Direct analytical optimization prevents gradient instability
- **Batch Processing**: Ideal for offline recommendation systems

**❌ Disadvantages:**
- **Memory Intensive**: Requires matrix inversions and more storage
- **Computational Cost**: O(k³ + nk²) complexity per iteration
- **Batch Only**: Not suitable for real-time online learning

### 🔹 Stochastic Gradient Descent (SGD)
SGD updates factors incrementally using gradient-based optimization for each observed rating.

```cpp
// SGD update rules
error = R_ij - dot(U_i, V_j)
U_i += learning_rate * (error * V_j - lambda * U_i)
V_j += learning_rate * (error * U_i - lambda * V_j)
```

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
│   └── 📄 ratings.csv              # Preprocessed MovieLens 100K dataset
├── 📁 include/
│   ├── 📄 ALS.hpp                  # ALS algorithm header
│   ├── 📄 SGD.hpp                  # SGD algorithm header
│   ├── 📄 MatrixFactorization.hpp  # Base class interface
│   └── 📄 utils.hpp                # Utility functions and metrics
├── 📁 src/
│   ├── 📄 ALS.cpp                  # ALS implementation
│   ├── 📄 SGD.cpp                  # SGD implementation
│   ├── 📄 main.cpp                 # Main program and experiments
│   └── 📄 utils.cpp                # Helper functions
├── 📁 results/
│   ├── 📄 performance_metrics.txt  # Final RMSE/MAE results
│   └── 📄 convergence_data.csv     # Iteration-by-iteration metrics
├── 📁 plots/
│   ├── 📊 als_convergence.png      # ALS learning curves
│   └── 📊 sgd_convergence.png      # SGD learning curves
├── 📄 Makefile                     # Build configuration
├── 📄 requirements.txt             # Dataset requirements
└── 📄 README.md                    # This file
```

---

## 🚀 Quick Start

### Prerequisites
- **C++17** compatible compiler (GCC 7+, Clang 5+, or MSVC 2017+)
- **Make** build system
- **Git** for cloning the repository

### Installation & Execution

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/movie-recommendation-cpp.git
   cd movie-recommendation-cpp
   ```

2. **Download the dataset:**
   ```bash
   # The MovieLens 100K dataset will be automatically processed
   # Or manually download from: https://grouplens.org/datasets/movielens/100k/
   ```

3. **Build the project:**
   ```bash
   make clean && make
   ```

4. **Run the comparative analysis:**
   ```bash
   ./recommender
   ```

5. **View results:**
   ```bash
   # Performance metrics
   cat results/performance_metrics.txt
   
   # Convergence analysis
   cat results/convergence_data.csv
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

### Example Configuration:
```cpp
// Optimal parameters found through experimentation
const int k = 50;              // Latent factors
const double lambda = 0.1;     // Regularization
const double eta = 0.01;       // SGD learning rate
const int iterations = 30;     // Max iterations
```

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

## 🛠️ Advanced Features & Optimization

### Code Optimizations Implemented:
- **Memory-efficient** sparse matrix representations
- **Vectorized operations** for improved performance
- **Cache-friendly** data access patterns
- **Early stopping** based on validation metrics
- **Regularization** to prevent overfitting

### Future Enhancements:
- [ ] **Parallel ALS** implementation using OpenMP
- [ ] **Mini-batch SGD** for improved stability
- [ ] **Adaptive learning rates** (Adam, RMSprop)
- [ ] **Implicit feedback** support
- [ ] **Deep learning hybrid** models
- [ ] **Distributed computing** with Apache Spark

---

## 📚 Dataset Information

This project uses the **MovieLens 100K** dataset:
- **100,000 ratings** from 943 users on 1,682 movies
- **Rating scale**: 1-5 stars
- **Sparsity**: ~95% (typical of real-world scenarios)
- **Format**: CSV with columns (user_id, item_id, rating)

The dataset simulates a real-world scenario similar to Netflix, where the vast majority of user-item pairs are unobserved, making accurate prediction challenging and practically relevant.

---

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Areas for Contribution:
- Performance optimizations
- Additional algorithms (NMF, Deep Learning)
- Better visualization tools
- Code documentation improvements
- Bug fixes and testing

---

## 📝 Citation

If you use this code in your research, please cite:

```bibtex
@misc{basantes2024movie,
  title={A C++ Implementation and Comparative Study of ALS and SGD for Movie Recommendation Using Matrix Factorization},
  author={Basantes Balcazar, Andres Alexander},
  year={2024},
  institution={Universidad Yachay Tech},
  url={https://github.com/yourusername/movie-recommendation-cpp}
}
```

---

## 👨‍💻 Author

**Andres Alexander Basantes Balcazar**  
🎓 School of Mathematical and Computational Sciences  
🏫 Universidad Yachay Tech, Ecuador  
📧 [andres.basantes@yachaytech.edu.ec](mailto:andres.basantes@yachaytech.edu.ec)  
🔗 [LinkedIn](https://linkedin.com/in/yourusername) | [GitHub](https://github.com/yourusername)

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **GroupLens Research** for providing the MovieLens dataset
- **Universidad Yachay Tech** for academic support
- **Netflix Prize** competition for inspiring matrix factorization research
- **Open source community** for C++ libraries and tools

---

<div align="center">

**⭐ Star this repository if you found it helpful! ⭐**

Made with ❤️ for the recommender systems community

</div>
