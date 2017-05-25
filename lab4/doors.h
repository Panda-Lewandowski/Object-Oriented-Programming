#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>

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
    void set_label(QLabel* l);

private:
  doors_state st;
  QLabel* lab;
  void set_state(doors_state state);


public slots:
  void opening();    //открыть
  void closing();   //закрыть

signals:
  void open();     //двери открыты
  void close();    //двери закрыты

};

#endif // DOORS_H
