
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
    // Copy constructor (deep copy)
    Quiz(const Quiz &other);

    Quiz& operator =(const Quiz &other);

    // Shallow copy constructor
    Quiz(Quiz &&other) noexcept;
    Quiz& operator = (Quiz &&other) noexcept;

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
     void deepCopy(const Quiz &other);
};

#endif // QUIZ_H