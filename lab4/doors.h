#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>
#include <QTimer>

class doors : public QObject
{
    Q_OBJECT
    enum doors_state
    {
        opened_state,
        closed_state,
        opening_state,
        closing_state
    };

public:
    doors(); //конструктор дверей
    void set_label(QLabel* l);
    bool is_open();

private:
  doors_state st;
  QLabel* lab;
  void set_state(doors_state state);
  QTimer timer_opening;
  QTimer timer_closing;


public slots:
  void open();    //открыть
  void close();   //закрыть
  void start_open();    //начать открывать
  void start_close();   //начать закрывать

signals:
  void opening();     //двери открыты
  void closing();    //двери закрыты

};

#endif // DOORS_H
