#include <iostream>

double w_sum(double* input, double* weights) {
    double output = 0.0;
    for(int i = 0; i < sizeof(input); i++) {
        output += (input[i] * weights[i]); //происходит магия. Вся суть прямого распространения
    }
    return output;
}

double nerual_network(double* input, double* weights) {
    double pred = w_sum(input, weights);
    return pred;
}

int main()
{
    double weights[] = {0.1, 0.2, 0}; //Веса. Меняем веса - меняем предикт

    // Этот набор данных определяет текущее состояние
    //перед началом каждой из первых четырех игр в сезоне:
    //toes = текущее среднее число игр, сыгранных игроками.
    //wlrec = текущая доля игр, окончившихся победой (процент)
    //nfans = число болельщиков (в миллионах)
    double toes[] = {8.5, 9.5, 9.9, 9.0};
    double wlrec[] = {0.65, 0.8, 0.8, 0.9};
    double nfans[] = {1.2, 1.3, 0.5, 1.0};

    double input[] = {toes[0], wlrec[0], nfans[0]}; //Запись, соответсвующая первой игре в сезоне
    double pred = nerual_network(input, weights); // предсказываем
    std::cout << pred << std::endl; //вывод в консоль
    return 0;
}
