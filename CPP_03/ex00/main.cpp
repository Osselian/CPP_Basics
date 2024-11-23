#include "ClapTrap.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

TEST_CASE("Testing ClapTrap class")
{
    // Arrange
    ClapTrap    matevos("matevos");
    ClapTrap    mate("mate");
    ClapTrap    mat("mat");
    ClapTrap    ma = mat;
    ClapTrap    ma2;
    ClapTrap    m;
    ClapTrap    m2("m2");

    ma2 = ma;
    int N = 5;

    // Act
    for (int i = 0; i < N; i++)
        matevos.attack("mat");
    mat.takeDamage(N * 0);

    N = 9;
    for (int i = 0; i < N; i++)
        mat.attack("matevos");
    matevos.takeDamage(0);
    matevos.beRepaired(N * 0);

    N = 10;
    for (int i = 0; i < N / 2; i++)
        ma.attack("ma2");
    ma2.takeDamage(N * 0);
    ma2.beRepaired(N);

    N = 100;
    ma.attack("nameless");
    m.takeDamage(N * 0);
    m.beRepaired(N + N);

    for (int i = 0; i < 15; i++)
        mate.attack("m2");
    m2.takeDamage(15 * 0);

    // Assert
    //CHECK_EQ(matevos.getEP(), 5 - 1);

//    CHECK_EQ(mat.getEP(), 1);

//    CHECK_EQ(ma.getEP(), 5 - 1);
  //  CHECK_EQ(ma2.getEP(), 10 - 1);
    //CHECK_EQ(m.getEP(), 10 - 1);

//    CHECK_EQ(mate.getAD(), 0);
  //  CHECK_EQ(mate.getEP(), 0);
}


#include "ClapTrap.hpp"

//int main()
//{
//	ClapTrap a("A");
//	ClapTrap b("B");
//	ClapTrap c(a);

//	a.attack("B");
//	a.takeDamage(5);
//	a.takeDamage(0);
//	a.takeDamage(-5);
//	a.beRepaired(4);

//	a = b;
//	a.takeDamage(9);
//	a.beRepaired(4);
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.attack("B");
//	a.beRepaired(4);
//	a.beRepaired(4);
//	a.beRepaired(4);
//}