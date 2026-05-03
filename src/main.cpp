#include <fraction.hpp>

using namespace std;

int main(void) {
    Fraction fract1(2, 3);
    Fraction fract2(1, 2);

    cout << "fract1: " << fract1 << endl;
    cout << "fract2: " << fract2 << endl;
    cout << "Result of +fract1: " << +fract1 << endl;
    cout << "Result of -fract2: " << -fract2 << endl;

    Fraction fract3(3, 4);
    Fraction fract4(4, 5);
    Fraction fract5(5, 6);
    Fraction fract6(6, 7);
    cout << "fract3: " << fract3 << endl;
    cout << "fract4: " << fract4 << endl;
    cout << "fract5: " << fract5 << endl;
    cout << "fract6: " << fract6 << endl << endl;
    ++fract3;
    --fract4;
    fract5++;
    fract6--;
    cout << "Result of ++fract3: " << fract3 << endl;
    cout << "Result of --fract4: " << fract4 << endl;
    cout << "Result of fract5++: " << fract5 << endl;
    cout << "Result of fract6--: " << fract6 << endl << endl;

    Fraction fract7(3, 5);
    Fraction fract8(4, 7);
    Fraction fract9(5, 8);
    Fraction fract10(7, 9);
    fract7 += 2;
    fract8 -= 3;
    fract9 *= 4;
    fract10 /= 5;
    cout << "Result of fract7 += 2: " << fract7 << endl;
    cout << "Result of fract8 -= 3: " << fract8 << endl;
    cout << "Result of fract9 *= 4: " << fract9 << endl;
    cout << "Result of fract10 /= 5: " << fract10 << endl << endl;

    Fraction fract11(1, 2);
    Fraction fract12(3, 4);
    cout << "fract11: " << fract11 << endl;
    cout << "fract12: " << fract12 << endl;
    cout << "fract11 + fract12: " << fract11 + fract12 << endl;
    cout << "fract11 - fract12: " << fract11 - fract12 << endl;
    cout << "fract11 * fract12: " << fract11 * fract12 << endl;
    cout << "fract11 / fract12: " << fract11 / fract12 << endl << endl;

    Fraction fract13(2, 3);
    Fraction fract14(1, 3);
    cout << "fract13: " << fract13 << endl;
    cout << "fract14: " << fract14 << endl;
    cout << "fract13 == fract14: " << boolalpha << (fract13 == fract14) << endl;
    cout << "fract13 != fract14: " << boolalpha << (fract13 != fract14) << endl;
    cout << "fract13 > fract14: " << boolalpha << (fract13 > fract14) << endl;
    cout << "fract13 < fract14: " << boolalpha << (fract13 < fract14) << endl << endl;

    Fraction fract15(5);
    Fraction fract16(24.45); // Double to fraction conversion
    cout << "fract15: " << fract15 << endl;
    cout << "fract16: " << fract16 << endl << endl;

    Fraction fract17(9, 13);
    cout << "double value of fract17 (9, 13): "
        << setprecision(2) << fract17.operator double() << endl << endl;

    Fraction fract18;
    cin >> fract18;
    cout << "fract18: " << fract18 << endl;
    return 0;
}
