#ifndef SEARCHDIALOGWIDGET_H
#define SEARCHDIALOGWIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QShortcut>
#include <QDialog>

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = 0);
    QLabel *m_label;
    QString getFindText();

public slots:
    void find_next();

private:
    QLineEdit *m_searchInput;
    QPushButton *m_cancel;
    QPushButton *m_findNext;
    QString findText;
};

#endif // SEARCHDIALOGWIDGET_H