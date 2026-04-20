# 📰 Fake News Detection using NLP

## 📌 Overview

This project implements a complete Natural Language Processing (NLP) pipeline to classify news articles as **FAKE** or **REAL** using machine learning techniques. The system focuses on text preprocessing, feature extraction, and model evaluation to achieve high classification performance.

---

## 🧠 Key Features

* End-to-end NLP pipeline for text classification
* Multiple preprocessing strategies (stemming vs lemmatization)
* Feature extraction using Bag-of-Words and TF-IDF
* Model comparison across different algorithms
* Performance evaluation using standard ML metrics

---

## ⚙️ Methodology

### 1. Data Preprocessing

* Lowercasing text
* Removing URLs, punctuation, and digits
* Tokenization
* Stopword removal
* Stemming (Porter Stemmer)
* Lemmatization (WordNet Lemmatizer)

### 2. Feature Extraction

* Bag-of-Words (CountVectorizer)
* TF-IDF (TfidfVectorizer)

### 3. Models Used

* Naive Bayes
* Logistic Regression
* Support Vector Machine (SVM)

---

## 📊 Evaluation

Models were evaluated using:

* Accuracy
* Precision
* Recall
* F1-score
* Confusion Matrix

---

## 🏆 Results

* Best model: **TF-IDF + SVM**
* Achieved up to **93% accuracy**

---

## 🛠️ Technologies

* Python
* Scikit-learn
* NLTK
* Pandas / NumPy

---

## 📂 Project Structure

```
data/
preprocessing/
models/
evaluation/
main.py
README.md
```

---

## 🚀 How to Run

```bash
git clone <your-repo-link>
cd <project-folder>
pip install -r requirements.txt
python main.py
```

---

## 📈 Future Improvements

* Use deep learning models (LSTM, BERT)
* Deploy as a web application
* Expand dataset for better generalization

---

## 👩‍💻 Team

* Eman Ashraf
* Raheeq Mohamed
* Habiba Yousry
* Salma Emad
* Sama Khaled
* Nada Tarek
* Shrouk Aboalela
