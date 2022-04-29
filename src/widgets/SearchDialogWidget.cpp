#include "SearchDialogWidget.h"
#include <QtWidgets>

SearchDialog::SearchDialog(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Search Dialog");

    m_label = new QLabel(tr("Search:"));
    m_searchInput = new QLineEdit;
    m_findNext = new QPushButton(tr("&Find"));
    m_cancel = new QPushButton(tr("&Close"));
    findText = "";

    connect(m_cancel, &QPushButton::clicked, this, &SearchDialog::close);
    connect(m_findNext, &QPushButton::clicked, this, &SearchDialog::find_next);
    new QShortcut(QKeySequence(Qt::Key_Enter), this, SLOT(find_next()));
    new QShortcut(QKeySequence(Qt::Key_Return), this, SLOT(find_next()));

    QHBoxLayout *findLayout = new QHBoxLayout();
    findLayout->addWidget(m_label);
    findLayout->addWidget(m_searchInput);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(m_findNext);
    buttonsLayout->addWidget(m_cancel);

    QVBoxLayout *windowLayout = new QVBoxLayout();
    windowLayout->addLayout(findLayout);
    windowLayout->addLayout(buttonsLayout);

    this->setLayout(windowLayout);
}

void SearchDialog::find_next()
{
    QString text = m_searchInput->text();
    if (text.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"), tr("Please enter a value."));
        return;
    } else {
        findText = text;
        // m_searchInput->clear();
        // hide();
    }
    /*
    if (!m_searchInput->text().isEmpty())
    {
        QString searchString = m_searchInput->text();
        emit new_search(searchString);
    }
    */
}

QString SearchDialog::getFindText()
{
    return findText;
}
