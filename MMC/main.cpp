
// ================================================================================================
// 
// @file main.cpp
// @brief MMC entry point
// @author Jose Fernando Lopez Fernandez
// @date 11-April-2019
// @version 0.1.0
//
// ================================================================================================

#include "MMC.hpp"
#include "main.h"

namespace MMC {

// ================================================================================================
// Constants
// ================================================================================================

// TODO: Add constants.

// ================================================================================================
// Arithmetic
// ================================================================================================

template <typename T>
auto Sq(T arg)
{
    return (arg * arg);
}

// ================================================================================================
// Sum
// ================================================================================================

template <typename T>
auto Sum(const std::vector<T>& list)
{
    T sum = 0;

    for (const auto& l : list)
    {
        sum += l;
    }

    return sum;
}

template <typename T>
auto Sum(T arg)
{
    return arg;
}

template <typename T, typename... Types>
auto Sum(T arg, Types... args)
{
    return arg + Sum(args...);
}

// ================================================================================================
// Count
// ================================================================================================

template <typename T, typename UnsignedIntegralType = UInt>
UnsignedIntegralType Count(const std::vector<T>& list)
{
    return list.size();
}

template <typename T, typename UnsignedIntegralType = UInt>
UnsignedIntegralType Count(T arg)
{
    return 1;
}

template <typename T, typename... Types, typename UnsignedIntegralType = UInt>
UnsignedIntegralType Count(T arg, Types... args)
{
    return 1 + Count(args...);
}
    
// ================================================================================================
// Probability
// ================================================================================================

template <typename T, typename FloatingPointType = Real>
FloatingPointType Mean(const std::vector<T>& list)
{
    const T   sum  =   Sum(list);
    const Int size = Count(list);

    return (FloatingPointType) sum / (FloatingPointType) size;
}

template <typename UnsignedIntegralType = UInt>
UnsignedIntegralType Factorial(UnsignedIntegralType n)
{
    return (n <= 1) ? 1 : n * Factorial(n - 1);
}

template <typename UnsignedIntegralType = UInt>
UnsignedIntegralType Permutations(UnsignedIntegralType n, UnsignedIntegralType r)
{
    return Factorial(n) / Factorial(n - r);
}

template <typename UnsignedIntegralType = UInt>
UnsignedIntegralType Combinations(UnsignedIntegralType n, UnsignedIntegralType r)
{
    return Permutations(n, r) / Factorial(r);
}

template <typename T>
auto SumOfSquares(const std::vector<T>& vx)
{
    const auto mean = Mean(vx);

    T sum = 0;

    for (const auto& x : vx)
    {
        sum += Sq(x - mean);
    }

    return sum;
}

// ================================================================================================
// Neural Network Activation Functions
// ================================================================================================

template <typename FloatingPointType = Real>
FloatingPointType BinaryActivationFunction(FloatingPointType input)
{
    return (input < 0) ? 0 : 1;
}

template <typename FloatingPointType = Real>
FloatingPointType SigmoidActivationFunction(FloatingPointType input)
{
    return 1.0 / (1 + std::exp(-(input)));
}

template <typename FloatingPointType = Real>
FloatingPointType HyperbolicTangentActivationFunction(FloatingPointType input)
{
    return std::tanh(input);
}

template <typename FloatingPointType = Real>
FloatingPointType ArcTanActivationFunction(FloatingPointType input)
{
    return std::atan(input);
}

template <typename FloatingPointType = Real>
FloatingPointType IdentityActivationFunction(FloatingPointType input)
{
    return input;
}

// ================================================================================================
// Neural Network Data Types
// ================================================================================================

class Perceptron {
    Real  bias;
    Real* inputs;
    Real* output; // QUESTION: Is this necessary?
    Real (*activationFunction)(Real input);

public:
    Perceptron(Real bias, Real* inputs, Real* output, Real (*activationFunction)(Real input))
        : bias { bias }, inputs { inputs }, output { output }, activationFunction { activationFunction }
    {
        // Default constructor.
    }

    // TODO: Implement perceptron evaluate() function.
    Real evaluate()
    {
        return 0.0;
    }
};

class NeuralNetwork {
    Perceptron* root;

public:
    NeuralNetwork(Perceptron* root)
        : root { root }
    {
        // Default constructor.
    }
    
    // TODO: Implement evaluate() function. The plan is for the function
    // to work recursively; it will call the root perceptron and each
    // one will in turn call their own 'evaluate()' function which will
    // be a pretty standard recursive traversion of a multibranched tree.
    Real evaluate()
    {
        return 0.0;
    }
};

} // namespace MMC

using namespace MMC;

// ================================================================================================
// Main
// ================================================================================================

int main()
{
    std::cout.imbue(std::locale("en_US"));

    Real (*activationFunction)(Real input) = HyperbolicTangentActivationFunction;

    const Real x = 3.7;
    const Real y = activationFunction(x);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    return EXIT_SUCCESS;
}
