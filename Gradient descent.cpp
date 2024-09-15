#include <iostream>
#include <cmath>

int main()
{
    double weight = 0.5;
    double goal_pred = 0.8; // процент наблюдений (допустим "процент людей, надевших теплую одежду")
    double input = 2.0;
    double alpha = 0.1; // предотвращает избыточную коррекцию весов

    for(int i = 0; i < 20; i++) {
        double pred = input * weight;
        double error = std::pow((pred - goal_pred), 2); // (pred - goal_pred) - чистая ошибка. Возведеение в квдарат позволяет
                                                        // уйти от отрицательных значений, так как отрицательные ошибки
                                                        // не имеют смысла
        double derivative = input * (pred - goal_pred); // вычисление производной (суть градиентного спуска)
        weight -= (alpha * derivative); // изменение веса на коэффициент

        std::cout << "Error: " << error << " " << "Prediction: " << pred << std::endl;
    }
    return 0;
}
