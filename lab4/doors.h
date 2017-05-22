#ifndef DOORS_H
#define DOORS_H

#include <QObject>

class doors : public QObject
{
    Q_OBJECT


public:
    enum doors_state
    {
        opening_state,
        closing_state,
        opened_state,
        closed_stete
    };
    doors(); //конструктор дверей

private:
  doors_state st;
  void set_state(int);

public slots:
  void opening();   //двери открываются
  void open();     //двери открыты
  void closing();  //двери закрываются
  void close();    //двери закрыты

signals:
  void opened();    //открыты
  void closed();   //закрыты
};

#endif // DOORS_H
