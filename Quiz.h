
#ifndef QUIZ_H
#define QUIZ_H

#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

class Quiz : public QDialog {
Q_OBJECT

public:
    Quiz(const QString &question, const QStringList &answers, int correctIndex, QWidget *parent = nullptr);
    ~Quiz();

private slots:
    void handleAnswer(int index);

private:
    QString question;
    QString *answers;
    int correctIndex;
    QLabel *questionLabel;
    QLabel *resultLabel;
    QPushButton *retryButton;
    QPushButton **answerButtons;
    QVBoxLayout *layout;
    int answerCount;
};

#endif // QUIZ_H