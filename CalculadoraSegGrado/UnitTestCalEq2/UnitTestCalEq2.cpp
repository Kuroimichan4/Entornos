#include "pch.h"
#include "CppUnitTest.h"
#include "../CalSegundoGrado/CalSegundoGrado.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCalEq2
{
	TEST_CLASS(UnitTestCalEq2)
	{
	public:

        TEST_METHOD(TestConSolucionesReales)
        {
            a = 1;
            b = -3;
            c = 2;
            CalcularDatos();

            Assert::AreEqual(1.0, ObtenerX2(), L"Error en la solución x2: el resultado no es el esperado.");
            Assert::AreEqual(2.0, ObtenerX1(), L"Error en la solución x1: el resultado no es el esperado.");
        }

        // Test para el caso con una única solución real (discriminante igual a cero)
        TEST_METHOD(TestConUnaSolucionUnica)
        {
            a = 1;
            b = -2;
            c = 1;
            CalcularDatos();

            Assert::AreEqual(1.0, ObtenerResultadoUnico(), L"Error en la solución única: el resultado no es el esperado.");
        }

        // Test para el caso con discriminante negativo (sin soluciones reales)
        TEST_METHOD(TestSinSolucionesReales)
        {
            a = 1;
            b = 2;
            c = 3;
            CalcularDatos();

            //N hay soluciones reales
            Assert::IsTrue(isnan(ObtenerRaiz()), L"Error: La raíz debe ser NaN cuando no hay soluciones reales.");
        }//isnan() es una función de la librería estándar de C++ que se usa para verificar si un valor es "NaN" (Not a Number)
    };
}