/**
 * @file mathTest.cpp
 * @author Tomas Polesovsky, Miroslav Pavelek, Ivan Sevcik, Zdenek Sklenar
 * @brief Test cases for summation, subtraction, multiplication, division, factorial, exponentiation and root extraction
 */


#include <QtTest>
#include <stdexcept>

#include "inc/core/math.h"
#include "inc/tests/mathTestHeader.h"


//! Summation
void mathTestHeader::testSum() {
//zero
    QCOMPARE(Math::add(0,0),0.0);
//positive numbers
    QCOMPARE(Math::add(0,2),2.0);
    QCOMPARE(Math::add(0,15),15.0);
    QCOMPARE(Math::add(5,4),9.0);
    QCOMPARE(Math::add(4,5),9.0);
    QCOMPARE(Math::add(9.5,8.8),18.3);
    QCOMPARE(Math::add(65536,2000),67536.0);
//negative numbers
    QCOMPARE(Math::add(0,-1),-1.0);
    QCOMPARE(Math::add(-2,-5),-7.0);
    QCOMPARE(Math::add(-5,-2),-7.0);
    QCOMPARE(Math::add(-90.8,-29.2),-120.0);
    QCOMPARE(Math::add(-65536,-1000),-66536.0);
//positive and negative numbers
    QCOMPARE(Math::add(-5,5),0.0);
    QCOMPARE(Math::add(-20,2),-18.0);
    QCOMPARE(Math::add(2,-20),-18.0);
    QCOMPARE(Math::add(-71234,70569),-665.0);
}


//! Subtraction
void mathTestHeader::testSub() {
//zero
    QCOMPARE(Math::sub(0,0),0.0);
//positive numbers
    QCOMPARE(Math::sub(0,2),-2.0);
    QCOMPARE(Math::sub(0,15),-15.0);
    QCOMPARE(Math::sub(5,4),1.0);
    QCOMPARE(Math::sub(4,5),-1.0);
    QCOMPARE(Math::sub(11,8.5),2.5);
    QCOMPARE(Math::sub(67539,2000),65539.0);
//first negative
    QCOMPARE(Math::sub(-2,5),-7.0);
    QCOMPARE(Math::sub(-5,2),-7.0);
    QCOMPARE(Math::sub(-90.3,29.2),-119.1);
    QCOMPARE(Math::sub(-65536,1000),-66536.0);
}


//! Multiplication
void mathTestHeader::testMul() {
//by zero
    QCOMPARE(Math::mul(0,0),0.0);
    QCOMPARE(Math::mul(0,2),0.0);
    QCOMPARE(Math::mul(2,0),0.0);
    QCOMPARE(Math::mul(0,-15),0.0);
    QCOMPARE(Math::mul(-15,0),0.0);
    QCOMPARE(Math::mul(2.5,0),0.0);
//by positive and negative one
    QCOMPARE(Math::div(1,1),1.0);
    QCOMPARE(Math::div(-6,1),-6.0);
    QCOMPARE(Math::div(15,1),15.0);
    QCOMPARE(Math::div(1,-1),1.0);
    QCOMPARE(Math::div(-7,-1),7.0);
    QCOMPARE(Math::div(10,-1),-10.0);
//positive numbers
    QCOMPARE(Math::mul(5,4),20.0);
    QCOMPARE(Math::mul(4,5),20.0);
    QCOMPARE(Math::mul(4,2.5),10.0);
    QCOMPARE(Math::mul(11,8),88.0);
    QCOMPARE(Math::mul(260,256),66560.0);
//negative numbers
    QCOMPARE(Math::mul(-2,-5),10.0);
    QCOMPARE(Math::mul(-50.5,-2),101.0);
    QCOMPARE(Math::mul(-12,-13),156.0);
    QCOMPARE(Math::mul(-260,-256),-66560.0);
//positive and negative numbers
    QCOMPARE(Math::mul(-5,8),-40.0);
    QCOMPARE(Math::mul(5,-8),-40.0);
    QCOMPARE(Math::mul(-5.2,8),-41.6);
    QCOMPARE(Math::mul(-20,2),-18.0);
    QCOMPARE(Math::mul(2,-20),-18.0);
    QCOMPARE(Math::mul(-321,312),-100152.0);
}


//! Division
void mathTestHeader::testDiv() {
//by zero
    QVERIFY_EXCEPTION_THROWN(Math::div(0,0),std::invalid_argument);
    QVERIFY_EXCEPTION_THROWN(Math::div(-5,0),std::invalid_argument);
    QVERIFY_EXCEPTION_THROWN(Math::div(5,0),std::invalid_argument);
//by positive and negative one
    QCOMPARE(Math::div(1,1),1.0);
    QCOMPARE(Math::div(-5,1),-5.0);
    QCOMPARE(Math::div(10.2,1),10.2);
    QCOMPARE(Math::div(1,-1),1.0);
    QCOMPARE(Math::div(-8,-1),8.0);
    QCOMPARE(Math::div(10,-1),-10.0);
//positive numbers
    QCOMPARE(Math::div(8,4),2.0);
    QCOMPARE(Math::div(50,5),10.0);
    QCOMPARE(Math::div(75000,5),15000.0);
    QCOMPARE(Math::div(50,5),10.0);
    QCOMPARE(Math::div(5,10),0.5);
//negative numbers
    QCOMPARE(Math::div(-8,-4),2.0);
    QCOMPARE(Math::div(-70,-7),10.0);
    QCOMPARE(Math::div(-75000,-5),15000.0);
    QCOMPARE(Math::div(-60,-6),10.0);
    QCOMPARE(Math::div(-8,-16),0.5);
//positive and negative numbers
    QCOMPARE(Math::div(9,-3),-3.0);
    QCOMPARE(Math::div(-50,5),10.0);
    QCOMPARE(Math::div(-75000,5),-15000.0);
    QCOMPARE(Math::div(60,-6),-10.0);
    QCOMPARE(Math::div(-6,-12),0.5);
}


//! Factorial
void mathTestHeader::testFac() {
//zero
    QCOMPARE(Math::fact(0),1);
// positive numbers
    QCOMPARE(Math::fact(1),1);
    QCOMPARE(Math::fact(2),2);
    QCOMPARE(Math::fact(4),24);
    QCOMPARE(Math::fact(10),3628800);
//negative numbers
    QVERIFY_EXCEPTION_THROWN(Math::fact(-1),std::invalid_argument);
    QVERIFY_EXCEPTION_THROWN(Math::fact(-5),std::invalid_argument);
    QVERIFY_EXCEPTION_THROWN(Math::fact(-10),std::invalid_argument);
}


//! Exponentiation
void mathTestHeader::testExp() {
// with zero
    QCOMPARE(Math::exp(0,0),0.0);
    QCOMPARE(Math::exp(0,2),0.0);
    QCOMPARE(Math::exp(50,0),1.0);
    QVERIFY_EXCEPTION_THROWN(Math::exp(0,-2),std::invalid_argument);
// positive numbers
    QCOMPARE(Math::exp(2,3),8.0);
    QCOMPARE(Math::exp(4,3),64.0);
    QCOMPARE(Math::exp(5.5,2),30.25);
//negative numbers
    QCOMPARE(Math::exp(-2,-2),0.25);
    QCOMPARE(Math::exp(-4,-3),-0.015625);
    QCOMPARE(Math::exp(-2.5,-3),-0.064);
//positive and negative numbers
    QCOMPARE(Math::exp(2,-3),0.125);
    QCOMPARE(Math::exp(-4,3),-64.0);
    QCOMPARE(Math::exp(-5.5,3),-166.375);
}


//! Root extraction
void mathTestHeader::testExt() {
// with zero
    QCOMPARE(Math::sqrt(0), 0.0);
// positive numbers
    QCOMPARE(Math::sqrt(4), 2.0);
    QCOMPARE(Math::sqrt(49), 7.0);
//first number is negative
    QVERIFY_EXCEPTION_THROWN(Math::sqrt(-2),std::invalid_argument);
}
