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

void Quiz::handleAnswer(int index) {
    if (index == correctIndex) {
        resultLabel->setText("Correct! Congratulations!");
        retryButton->hide();
        QMessageBox::information(this, "Congratulations!", "You picked the right answer");
        accept();
    } else {
        resultLabel->setText("Wrong! Are you sure your a pirate? Try again");
        retryButton->show();
        for (int i = 0; i < answerCount; ++i) {
            answerButtons[i]->hide();
        }
    }
}