#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    connect(ui->Login_PB, &QPushButton::clicked, this, &LoginDialog::onLoginButtonClicked);
    connect(ui->LoginGuest_PB, &QPushButton::clicked, this, &LoginDialog::onGuestLoginButtonClicked);
    connect(ui->Cancel_PB, &QPushButton::clicked, this, &LoginDialog::onCancelButtonClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLoginButtonClicked()
{
    QString username = ui->UserName_LE->text().trimmed();
    QString password = ui->Password_LE->text();

    if (username.isEmpty() || password.isEmpty())
    {
        emit loginFailed("用戶名和密碼不能為空！");
        QMessageBox::warning(this, "錯誤", "請輸入用戶名和密碼！");
        return;
    }

    // Validations
    if (validateCredentials(username, password))
    {
        emit loginSuccess(username, false);  // false: is not guest
        clearInputs();
        accept(); // return accept
    }
    else
    {
        emit loginFailed("用戶名或密碼錯誤！");
        QMessageBox::warning(this, "錯誤", "用戶名或密碼錯誤！");
        ui->Password_LE->clear();
        ui->Password_LE->setFocus();
    }
}

void LoginDialog::onGuestLoginButtonClicked()
{
    emit loginSuccess("Guest", true);  // true: is guest
    clearInputs();
    accept();
}

void LoginDialog::onCancelButtonClicked()
{
    clearInputs();
    reject();
}

bool LoginDialog::validateCredentials(const QString &username, const QString &password)
{
    // Validations
    if (username == "admin" && password == "password")
    {
        return true;
    }

    // return DatabaseManager::instance().validateUser(username, password);

    return false;
}

void LoginDialog::clearInputs()
{
    ui->UserName_LE->clear();
    ui->Password_LE->clear(); }
