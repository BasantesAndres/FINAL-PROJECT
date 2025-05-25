# 🎬 MatrixRecommender: Matrix Factorization with ALS and SGD in C++

This project implements a movie recommendation system using matrix factorization techniques. It compares two popular algorithms — Alternating Least Squares (ALS) and Stochastic Gradient Descent (SGD) — implemented in C++ with the Eigen linear algebra library. The MovieLens 100K dataset is used to train and evaluate model performance.

---

## 📌 Objective

To predict movie ratings that users have not yet rated, based on a sparse user-item interaction matrix. This is done using low-rank matrix factorization:

R ≈ U × Vᵗ

yaml
Copiar
Editar

Where:

- R is the user-item rating matrix
- U is the user feature matrix (users × k)
- V is the item feature matrix (items × k)
- k is the number of latent factors

---

## 📚 Methodology Overview

Matrix factorization is used to uncover latent patterns between users and items. This project compares two optimization algorithms:

- 📈 SGD: Updates U and V using stochastic gradient descent on each known rating.
- 🔁 ALS: Alternates between solving U and V using least squares optimization with regularization.

Both methods are evaluated using:

- RMSE (Root Mean Squared Error)
- MAE (Mean Absolute Error)

---

## 📁 Project Structure


---

## 🧩 File Descriptions

| File                | Description                                                |
|---------------------|------------------------------------------------------------|
| main.cpp            | Main execution logic: loads data, trains models, evaluates |
| als.cpp / .h        | ALS algorithm implementation                               |
| sgd.cpp / .h        | SGD algorithm implementation                               |
| matrix_loader.cpp/.h| Parses ratings.csv and prepares the dataset                |
| metrics.cpp / .h    | Functions for RMSE and MAE calculations                    |
| extensions.cpp / .h | Prints matrices and generates top-N recommendations        |
| ratings.csv         | User-item-rating triplets from MovieLens 100K              |
| 

---

## 🎓 Dataset

We use the MovieLens 100K dataset:  
📦 https://grouplens.org/datasets/movielens/100k/

It contains:

- 100,000 ratings
- 943 users
- 1,682 movies
- Ratings scale: 1 to 5

We converted the original .data format to CSV as:

```csv
user_id,item_id,rating
0,1,5
0,2,3
...
Place this file in: data/ratings.csv

```


> [!NOTE]
>
> ### Note for Windows
>
> On Windows, you may need to compile your code using
>
> ```sh
> g++ -std=c++17 main.cpp als.cpp sgd.cpp matrix_loader.cpp metrics.cpp extensions.cpp -I eigen -o recommend
> ```
>
> in order to see output. Also, the output executable may be called `main.exe`, in which case you'll run your code with:
>
> ```sh
> ./recommend    In WINDOWS

> ```

📊 Output & Evaluation
During execution, you will see output like:

Training with SGD...
SGD RMSE: 0.8357
SGD MAE:  0.6667

Training with ALS...
ALS RMSE: 0.6849
ALS MAE:  0.5263
Additionally, the following files will be generated:

sgd_metrics.csv and als_metrics.csv: RMSE/MAE per iteration

als_vs_sgd_all_graphs.xlsx: includes:

ALS RMSE plot

ALS MAE plot

SGD RMSE plot

SGD MAE plot


🤖 ALS vs. SGD Comparison
Algorithm	Strengths	Limitations
ALS	Fast convergence, parallelizable	Requires matrix inversion
SGD	Simple, online-capable	Slower convergence, tuning needed

📬 Contact
Developed by: Andrés Alexander Basantes Balcazar
Department of Mathematical and Computational Sciences
Universidad Yachay Tech, Ecuador
📧 Email: andres.basantes@yachaytech.edu.ec
