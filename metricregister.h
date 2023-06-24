#ifndef METRICREGISTER_H
#define METRICREGISTER_H


#include <QtCore/QMap>
#include <QtCore/QPair>
#include <QtCore/QDebug>

class MetricRegister
{
public:
    bool add_metr(int resp_t, int wait_t)
    {
        // Добавление метрики в ассоциативный массив
        metrics[key_counter] = qMakePair(resp_t, wait_t);
        key_counter++;
        return true;
    }

    bool show_metr()
    {
        // Вывод на экран всех значений, упорядоченных по ключу
        QMapIterator<int, QPair<int, int>> it(metrics);
        while (it.hasNext()) {
            it.next();
            qDebug() << "Key:" << it.key() << "Response Time:" << it.value().first
                     << "Wait Time:" << it.value().second;
        }
        return true;
    }

    int count_cometr(int key)
    {
        // Вычисление вспомогательной метрики: сумма времени ожидания и времени отклика для данного ключа
        int cometr = 0;
        if (metrics.contains(key)) {
            QPair<int, int> metric = metrics.value(key);
            cometr = metric.first + metric.second;
        }
        return cometr;
    }

private:
    QMap<int, QPair<int, int>> metrics;
    int key_counter = 0;
};


#endif // METRICREGISTER_H
