#include "MainMenu.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScreen>
#include <QPalette>

int Window::execute() {
    int argc = 0; // Dummy argc
    char *argv[] = {nullptr}; // Dummy argv
    QApplication app(argc, argv);

    // Create a dark color palette
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    darkPalette.setColor(QPalette::Text, QColor(200, 200, 200));  // Light gray text

    app.setPalette(darkPalette);
    app.setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    QWidget window;

    // Create buttons
    QPushButton button1("Button 1");
    QPushButton button2("Button 2");
    QPushButton button3("Button 3");
    QPushButton button4("Button 4");

    // Create horizontal layout for the first three buttons
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(&button1);
    hLayout->addWidget(&button2);
    hLayout->addWidget(&button3);

    // Create vertical layout to include the horizontal layout and the fourth button
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayout);
    vLayout->addWidget(&button4);

    // Set the vertical layout for the window
    window.setLayout(vLayout);

    // Center the window on the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - window.width()) / 2;
    int y = (screenGeometry.height() - window.height()) / 2;
    window.move(x, y);

    window.show();

    return app.exec();
}
