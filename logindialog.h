#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;

    bool validateCredentials(const QString &username, const QString &password);

    void clearInputs();

signals:
    void loginSuccess(const QString &username, bool isGuest);
    void loginFailed(const QString &errorMessage);

private slots:
    void onLoginButtonClicked();
    void onGuestLoginButtonClicked();
    void onCancelButtonClicked();
};

#endif // LOGINDIALOG_H
