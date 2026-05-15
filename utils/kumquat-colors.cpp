// vi:expandtab:shiftwidth=2:tabstop=2
/*
 * Copyright (c) 2026 Gordon N. Squash
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including
 * the next paragraph) shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class KQColorDialog: public QColorDialog
{
public:
  KQColorDialog (QWidget* parent = nullptr);

private:
  QClipboard* clipboard;

  void quit_clicked (bool checked);
  void copy_clicked (bool checked);
};

KQColorDialog::KQColorDialog (QWidget* parent):
 QColorDialog (parent)
{
  QVBoxLayout*       dialog_layout;
  QDialogButtonBox*  button_box;
  QPushButton*       copy_button;
  QPushButton*       quit_button;

  clipboard = qApp->clipboard ();

  setWindowTitle ("Color Browser");
  setOption (QColorDialog::NoButtons);
  setOption (QColorDialog::DontUseNativeDialog);
  dialog_layout = (QVBoxLayout*) layout ();

  copy_button = new QPushButton (QIcon::fromTheme ("edit-copy"),
                                 "Copy to C&lipboard");
  QObject::connect (copy_button, &QPushButton::clicked,
                    this, &KQColorDialog::copy_clicked);

  quit_button = new QPushButton (QIcon::fromTheme("application-exit"),
                                 "&Quit");
  QObject::connect (quit_button, &QPushButton::clicked,
                    this, &KQColorDialog::quit_clicked);

  button_box = new QDialogButtonBox ();
  /* Using HelpRole here left-justifies the "Copy to Clipboard" button. */
  button_box->addButton (copy_button, QDialogButtonBox::HelpRole);
  button_box->addButton (quit_button, QDialogButtonBox::AcceptRole);
  dialog_layout->addWidget (button_box);
}

void KQColorDialog::quit_clicked (bool checked)
{
  (void) checked;
  close ();
}

void KQColorDialog::copy_clicked (bool checked)
{
  (void) checked;
  clipboard->setText (currentColor ().name ());
}

int main (int argc, char ** argv)
{
  QApplication  app (argc, argv);
  KQColorDialog dialog;

  dialog.show ();
  return app.exec ();
}
