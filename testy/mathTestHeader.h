#ifndef mathTestHeader_H
#define mathTestHeader_H

#include <QTest>
class mathTestHeader : public QObject
{
    Q_OBJECT

private slots:
    void testSum();
    void testSub();
    void testMul();
    void testDiv();
    void testFac();
    void testExp();
    void testExt();
};


#endif // mathTestHeader_H
