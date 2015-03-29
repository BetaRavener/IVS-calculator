/********************************************//**
 *  Functional testing of math.h
 * Test cases for summation, subtraction, multiplication, division, factorial, exponentiation and root extraction
 ***********************************************/
#include <QTest>
#include <stdexcept>
#include "mathTestHeader.h"
//! Summation
void mathTestHeader::testSum() {
//zero
	QCOMPARE(Math::Math.sum(0,0),0)
//positive numbers
	QCOMPARE(Math::Math.sum(0,2),2)
	QCOMPARE(Math::Math.sum(0,15),15)
	QCOMPARE(Math::Math.sum(5,4),9)
	QCOMPARE(Math::Math.sum(4,5),9)
	QCOMPARE(Math::Math.sum(9.5,8.8),18.3)
	QCOMPARE(Math::Math.sum(65536,2000),67536)
//negative numbers
	QCOMPARE(Math::Math.sum(0,-1),-1)
	QCOMPARE(Math::Math.sum(-2,-5),-7)
	QCOMPARE(Math::Math.sum(-5,-2),-7)
	QCOMPARE(Math::Math.sum(-90.8,-29.2),-120)
	QCOMPARE(Math::Math.sum(-65536,-1000),-66536)
//positive and negative numbers
	QCOMPARE(Math::Math.sum(-5,5),0)
	QCOMPARE(Math::Math.sum(-20,2),-18)
	QCOMPARE(Math::Math.sum(2,-20),-18)
	QCOMPARE(Math::Math.sum(-71234,70569),-665)
}

//! Subtraction
void mathTestHeader::testSub() {
//zero
	QCOMPARE(Math::Math.sub(0,0),0)
//positive numbers
	QCOMPARE(Math::Math.sub(0,2),-2)
	QCOMPARE(Math::Math.sub(0,15),-15)
	QCOMPARE(Math::Math.sub(5,4),1)
	QCOMPARE(Math::Math.sub(4,5),-1)
	QCOMPARE(Math::Math.sub(11,8.5),2.5)
	QCOMPARE(Math::Math.sub(67539,2000),65539)
//first negative
	QCOMPARE(Math::Math.sub(-2,5),-7)
	QCOMPARE(Math::Math.sub(-5,2),-7)
	QCOMPARE(Math::Math.sub(-90.3,29.2),-119.1)
	QCOMPARE(Math::Math.sub(-65536,1000),-66536)
}

//! Multiplication
void mathTestHeader::testMul() {
//by zero
	QCOMPARE(Math::Math.mul(0,0),0)
	QCOMPARE(Math::Math.mul(0,2),0)
	QCOMPARE(Math::Math.mul(2,0),0)
	QCOMPARE(Math::Math.mul(0,-15),0)
	QCOMPARE(Math::Math.mul(-15,0),0)
	QCOMPARE(Math::Math.mul(2.5,0),0)
//by positive and negative one
	QCOMPARE(Math::Math.div(1,1),1)
	QCOMPARE(Math::Math.div(-6,1),-6)
	QCOMPARE(Math::Math.div(15,1),15)
	QCOMPARE(Math::Math.div(1,-1),1)
	QCOMPARE(Math::Math.div(-7,-1),7)
	QCOMPARE(Math::Math.div(10,-1),-10)
//positive numbers
	QCOMPARE(Math::Math.mul(5,4),20)
	QCOMPARE(Math::Math.mul(4,5),20)
	QCOMPARE(Math::Math.mul(4,2.5),10)
	QCOMPARE(Math::Math.mul(11,8),88)
	QCOMPARE(Math::Math.mul(260,256),66560)
//negative numbers
	QCOMPARE(Math::Math.mul(-2,-5),10)
	QCOMPARE(Math::Math.mul(-50.5,-2),101)
	QCOMPARE(Math::Math.mul(-12,-13),156)
	QCOMPARE(Math::Math.mul(-260,-256),-66560)
//positive and negative numbers
	QCOMPARE(Math::Math.mul(-5,8),-40)
	QCOMPARE(Math::Math.mul(5,-8),-40)
	QCOMPARE(Math::Math.mul(-5.2,8),-41.6)
	QCOMPARE(Math::Math.mul(-20,2),-18)
	QCOMPARE(Math::Math.mul(2,-20),-18)
	QCOMPARE(Math::Math.mul(-321,312),-100152)
}

//! Division
void mathTestHeader::testDiv() {
//by zero
	QVERIFY_EXCEPTION_THROWN(Math::Math.div(0,0),std::invalid_argument::invalid_argument)
	QVERIFY_EXCEPTION_THROWN(Math::Math.div(-5,0),std::invalid_argument::invalid_argument)
	QVERIFY_EXCEPTION_THROWN(Math::Math.div(5,0),std::invalid_argument::invalid_argument)
//by positive and negative one
	QCOMPARE(Math::Math.div(1,1),1)
	QCOMPARE(Math::Math.div(-5,1),-5)
	QCOMPARE(Math::Math.div(10.2,1),10.2)
	QCOMPARE(Math::Math.div(1,-1),1)
	QCOMPARE(Math::Math.div(-8,-1),8)
	QCOMPARE(Math::Math.div(10,-1),-10)
//positive numbers
	QCOMPARE(Math::Math.div(8,4),2)
	QCOMPARE(Math::Math.div(50,5),10)
	QCOMPARE(Math::Math.div(75000,5),15000)
	QCOMPARE(Math::Math.div(50,5),10)
	QCOMPARE(Math::Math.div(5,10),0.5)
//negative numbers
	QCOMPARE(Math::Math.div(-8,-4),2)
	QCOMPARE(Math::Math.div(-70,-7),10)
	QCOMPARE(Math::Math.div(-75000,-5),15000)
	QCOMPARE(Math::Math.div(-60,-6),10)
	QCOMPARE(Math::Math.div(-8,-16),0.5)
//positive and negative numbers
	QCOMPARE(Math::Math.div(9,-3),-3)
	QCOMPARE(Math::Math.div(-50,5),10)
	QCOMPARE(Math::Math.div(-75000,5),-15000)
	QCOMPARE(Math::Math.div(60,-6),-10)
	QCOMPARE(Math::Math.div(-6,-12),0.5)
}

//! Factorial
void mathTestHeader::testFac() {
//zero
	QCOMPARE(Math::Math.fac(0),0)
// positive numbers
	QCOMPARE(Math::Math.fac(1),1)
	QCOMPARE(Math::Math.fac(2),2)
	QCOMPARE(Math::Math.fac(4),24)
	QCOMPARE(Math::Math.fac(10),3628800)
//negative numbers
	QVERIFY_EXCEPTION_THROWN(Math::Math.fac(-1),std::invalid_argument::invalid_argument)
	QVERIFY_EXCEPTION_THROWN(Math::Math.fac(-5),std::invalid_argument::invalid_argument)
	QVERIFY_EXCEPTION_THROWN(Math::Math.fac(-10),std::invalid_argument::invalid_argument)
}

//! Exponentiation
void mathTestHeader::testExp() {
// with zero
	QCOMPARE(Math::Math.exp(0,0),0)
	QCOMPARE(Math::Math.exp(0,2),0)
	QCOMPARE(Math::Math.exp(50,0),1)
	QVERIFY_EXCEPTION_THROWN(Math::Math.exp(0,-2),std::invalid_argument::invalid_argument)
// positive numbers
	QCOMPARE(Math::Math.exp(2,3),8)
	QCOMPARE(Math::Math.exp(4,3),64)
	QCOMPARE(Math::Math.exp(5.5,2),30.25)
//negative numbers
	QCOMPARE(Math::Math.exp(-2,-2),-0.25)
	QCOMPARE(Math::Math.exp(-4,-3),-0.015625)
	QCOMPARE(Math::Math.exp(-2.5,-3),-0.064)
//positive and negative numbers
	QCOMPARE(Math::Math.exp(2,-3),0.125)
	QCOMPARE(Math::Math.exp(-4,3),-64)
	QCOMPARE(Math::Math.exp(-5.5,3),-166.375)
}
root extraction
//! Root extraction
void mathTestHeader::testExt() {
// with zero
	QCOMPARE(Math::Math.ext(0,0),0)
	QCOMPARE(Math::Math.ext(0,2),0)
	QVERIFY_EXCEPTION_THROWN(Math::Math.ext(2,0),std::invalid_argument::invalid_argument)
// positive numbers
	QCOMPARE(Math::Math.ext(4,2),2)
	QCOMPARE(Math::Math.ext(27,3),3)
//first number is negative
	QVERIFY_EXCEPTION_THROWN(Math::Math.ext(-2,2),std::invalid_argument::invalid_argument)
	QVERIFY_EXCEPTION_THROWN(Math::Math.ext(-4,-3),std::invalid_argument::invalid_argument)
	QVERIFY_EXCEPTION_THROWN(Math::Math.ext(-2.5,7),std::invalid_argument::invalid_argument)
// second number is negative - TO DO
	QCOMPARE(Math::Math.ext(16,-2),0.25)
}
