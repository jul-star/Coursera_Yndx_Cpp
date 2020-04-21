#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace ::std;

namespace white::w4::e03 {

struct Image1 {
    double quality{0.0};
    double freshness{0.0};
    double rating{0.0};
};

struct Params1 {
    double a{0.0};
    double b{0.0};
    double c{0.0};
};

class FunctionPart1
{
private:
    char operation;
    double value;
public:
    FunctionPart1(char new_operation, double new_value)
    {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const
    {
        if (operation == '+') {return value + source_value;}
        else if(operation == '-'){ return source_value - value; }
        else if(operation == '*'){return source_value * value;}
        else if(operation == '/'){return source_value / value;}
        else{
            throw invalid_argument("Apply:operation is not set");
        }
    }
    void Invert()
    {
        if (operation == '+'){operation='-';}
        else if(operation == '-')  {operation='+';}
        else if(operation == '*')  {operation='/';}
        else if(operation == '/')  {operation='*';}
    }
};

class Function1
{
private:
    vector<FunctionPart1> parts;
public:
    void AddPart(const char operation, double val)
    {
        parts.push_back({operation, val});
    }
    double Apply(double value) const
    {
        for(const FunctionPart1 & part: parts)
        {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert()
    {
        for(FunctionPart1 & part : parts)
        {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
};
class Wrapper{
public:

    static Function1 MakeWeightFunction(const Params1& params,
                                       const Image1& image)
    {
        Function1 function;

        function.AddPart('*', params.a);
        function.AddPart('-', image.freshness * params.b);
        function.AddPart('+', image.rating * params.c);

        return function;
    }

    static double ComputeImageWeight(const Params1& params, const Image1& image)
    {
        Function1 function = MakeWeightFunction(params, image);
        return function.Apply(image.quality);
    }

    static double ComputeQualityByWeight(const Params1& params,
                                         const Image1& image,
                                         double weight)
    {
        Function1 function = MakeWeightFunction(params, image);
        function.Invert();
        return function.Apply(weight);
    }
};
}
