#ifndef DOORS_H
#define DOORS_H

#include <QObject>

class doors : public QObject
{
    Q_OBJECT


public:
    enum doors_state
    {
        opened_state,
        closed_state
    };
    doors(); //конструктор дверей

private:
  doors_state st;
  void set_state(doors_state state);

public slots:
  void opening();    //открыть
  void closing();   //закрыть

signals:
  void open();     //двери открыты
  void close();    //двери закрыты

};

#endif // DOORS_H
