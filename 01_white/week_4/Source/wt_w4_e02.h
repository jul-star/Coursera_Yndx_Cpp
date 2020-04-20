#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace ::std;

namespace white::w4 {

struct Image {
    double quality{0.0};
    double freshness{0.0};
    double rating{0.0};
};

struct Params {
    double a{0.0};
    double b{0.0};
    double c{0.0};
};

class FunctionPart
{
private:
    char operation;
    double value;
public:
    FunctionPart(char new_operation, double new_value)
    {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const
    {
        if (operation == '+') {        return value + source_value;}
        if(operation == '-'){ return source_value-value;        }
        throw invalid_argument("Apply:operation is not set");
    }
    void Invert()
    {
        if (operation == '+'){operation='-';}
        else if(operation == '-')  {operation='+';}
    }
};

class Function
{
private:
    vector<FunctionPart> parts;
public:
    void AddPart(const char operation, double val)
    {
        parts.push_back({operation, val});
    }
    double Apply(double value)
    {
        for(const FunctionPart & part: parts)
        {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert()
    {
        for(FunctionPart & part : parts)
        {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
};

Function MakeWeightFunction(const Params& params,
                            const Image& image)
{    
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image)
{
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight)
{
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main()
{
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 46) << endl;
    return 0;
}

}
