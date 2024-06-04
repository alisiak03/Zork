#include "Quiz.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

Quiz::Quiz(const QString &question, const QStringList &answers, int correctIndex, QWidget *parent)
        : QDialog(parent), question(question), correctIndex(correctIndex), answerCount(answers.size()) {

    this->answers = new QString[answerCount];
    for (int i = 0; i < answerCount; ++i) {
        this->answers[i] = answers[i];
    }

    questionLabel = new QLabel(question, this);
    resultLabel = new QLabel(this);
    retryButton = new QPushButton("Retry", this);
    answerButtons = new QPushButton*[answerCount];
    layout = new QVBoxLayout(this);

    layout->addWidget(questionLabel);
    for (int i = 0; i < answerCount; ++i) {
        answerButtons[i] = new QPushButton(answers[i], this);
        layout->addWidget(answerButtons[i]);
        connect(answerButtons[i], &QPushButton::clicked, this, [this, i]() { handleAnswer(i); });
    }

    layout->addWidget(resultLabel);
    layout->addWidget(retryButton);

    connect(retryButton, &QPushButton::clicked, this, [this]() {
        resultLabel->clear();
        retryButton->hide();
        for (int i = 0; i < answerCount; ++i) {
            answerButtons[i]->show();
        }
    });

    retryButton->hide();
}

Quiz::~Quiz() {
    delete[] answers;
    delete[] answerButtons;
}

//deep copy constructor
Quiz::Quiz(const Quiz &other) {
    deepCopy(other);
}

//copy assignment operator
Quiz& Quiz::operator=(const Quiz &other) {
    if (this != &other) {
        delete[] answers;
        delete[] answerButtons;
        deepCopy(other);
    }
    return *this;
}

void Quiz::deepCopy(const Quiz &other) {
    question = other.question;
    correctIndex = other.correctIndex;
    answerCount = other.answerCount;

    answers = new QString[answerCount];
    for (int i = 0; i < answerCount; ++i) {
        answers[i] = other.answers[i];
    }

    answerButtons = new QPushButton*[answerCount];
    for (int i = 0; i < answerCount; ++i) {
        answerButtons[i] = new QPushButton(answers[i], this);
    }

    questionLabel = new QLabel(question, this);
    resultLabel = new QLabel(this);
    retryButton = new QPushButton("Retry", this);
    layout = new QVBoxLayout(this);

    layout->addWidget(questionLabel);
    for (int i = 0; i < answerCount; ++i) {
        layout->addWidget(answerButtons[i]);
        connect(answerButtons[i], &QPushButton::clicked, this, [this, i]() { handleAnswer(i); });
    }

    layout->addWidget(resultLabel);
    layout->addWidget(retryButton);

    connect(retryButton, &QPushButton::clicked, this, [this]() {
        resultLabel->clear();
        retryButton->hide();
        for (int i = 0; i < answerCount; ++i) {
            answerButtons[i]->show();
        }
    });

    retryButton->hide();
}

//shallow copy
Quiz::Quiz(Quiz &&other) noexcept
        : QDialog(other.parentWidget()), question(std::move(other.question)), answers(other.answers), correctIndex(other.correctIndex),
          questionLabel(other.questionLabel), resultLabel(other.resultLabel), retryButton(other.retryButton),
          answerButtons(other.answerButtons), layout(other.layout), answerCount(other.answerCount) {
    other.answers = nullptr;
    other.answerButtons = nullptr;
    other.questionLabel = nullptr;
    other.resultLabel = nullptr;
    other.retryButton = nullptr;
    other.layout = nullptr;
}

// shallow copy
Quiz& Quiz::operator=(Quiz &&other) noexcept {
    if (this != &other) {
        delete[] answers;
        delete[] answerButtons;

        question = std::move(other.question);
        answers = other.answers;
        correctIndex = other.correctIndex;
        answerButtons = other.answerButtons;
        questionLabel = other.questionLabel;
        resultLabel = other.resultLabel;
        retryButton = other.retryButton;
        layout = other.layout;
        answerCount = other.answerCount;

        other.answers = nullptr;
        other.answerButtons = nullptr;
        other.questionLabel = nullptr;
        other.resultLabel = nullptr;
        other.retryButton = nullptr;
        other.layout = nullptr;
    }
    return *this;
}

void Quiz::handleAnswer(int index) {
    if (index == correctIndex) {
        resultLabel->setText("Correct! Congratulations!");
        retryButton->hide();
        QMessageBox::information(this, "Congratulations!", "You picked the right answer and are freed from jail. Your next task is to get the treasure ");
        accept();
    } else {
        resultLabel->setText("Wrong! Are you sure you're a pirate? Try again");
        retryButton->show();
        for (int i = 0; i < answerCount; ++i) {
            answerButtons[i]->hide();
        }
    }
}