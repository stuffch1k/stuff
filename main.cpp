#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

/*
 * Дана программа, которая является заготовкой. В ней рассчитывается амлитуда сгенерированного синусоидального сигнала.
 *
 * Для работы программы необходимо:
 *
 *  - Написать функцию расчёта амлитуды колебания, принимающую на вход массив значений double по указателю и размер массива типа size_t.
 * Амплитуда колебания, есть максимальное за период отклонение колеблющейся величины от среднего за период значения
 *
 * - Написать функцию генерации синусоидального колебания в виде дискретного сигнала,
 * принимающую на вход
 *  - указатель на указатель на массив значений double и самостоятельно выделяющую под неё память,
 *  - размер массива типа size_t,
 *  - частоту генерируемого колебания freq в Герцах типа double,
 *  - амплитуду генерируемого сигнала ampl типа double.
 * Колебание считается по формуле x(t) = sin(t/freq)
 * Время от отсчёта колебания зависит как t = N/discr_freq
 * Для расчёта используется функция std::sin, принимающая на вход значение фазы в радианах.
 * Константа M_PI содержится в заголовочном файле math.h, для её использования нужно объявить макрос _USE_MATH_DEFINES
 *
 * В результате работы программа выдает на выход данные в виде
 *
 * Signal size is 100
 * frequency	ampl	campl
 * 100	0.3	0.0943408
 * 200	0.3	0.290353
 * 400	0.3	0.28261
 * 800	0.3	0.276732
 * 1600	0.3	0.294778
 * 3200	0.3	0.293544
 * 6400	0.3	0.300203
 * 12800	0.3	0.300479
 *
 * Эти данные необходимо вставить в Excel и построить графики зависимости амплитуды и рассчётной амплитуды от частоты.
 *
 * Свои функции amplitude и generate_sine определить в конце файла.
 *
 * Объяснить почему графики имеют такой вид.
 *
*/

constexpr double discr_freq = 44100; //частота дискретизации сигнала в Герцах

int main()
{
    std::cout << "Functions lab" << std::endl;

    constexpr size_t signal_size = 100; //размер массива сигнала

    double* newSignal = nullptr;

    std::cout << "Signal size is " << signal_size << std::endl;

    std::cout << "frequency\tampl\tcampl" << std::endl;
    double freq = 100.0;
    constexpr double sig_ampl = 2;

    void generate_sine(double** newSignal, size_t signal_size,double freq, double sig_ampl);
    double amplitude(double* newSignal,size_t signal_size);
    for(int i = 0; i<8; ++i)
    {
        generate_sine(&newSignal, signal_size, freq, sig_ampl);
        const auto ampl = amplitude(newSignal, signal_size);
        std::cout << freq << "\t" << sig_ampl << "\t" << ampl << std::endl;
        freq*=2;
    }
    delete[] newSignal;

    return 0;
}

void genareate_sine(double** newSignal, size_t signal_size,double freq, double sig_ampl)
{

    double* array = new double[signal_size];
    for (int i = 0; i<signal_size; i++)
    {
        array[i]=sig_ampl*(2*M_PI*freq*i)/discr_freq;
    }
    *newSignal = array;
}

double amplitude(double* newSignal,size_t signal_size)
{
    double mx=0, min=100000,avg;
    for (int i = 0; i<signal_size; i++)
    {
       avg+=newSignal[i];
       if (newSignal[i]<min) min= newSignal[i];
       if (newSignal[i]>mx) mx = newSignal[i];
    }
    avg=avg/signal_size;
    return fmax(mx-avg,avg-min);
}


/*
 * Здесь описать сфои функции
*/
