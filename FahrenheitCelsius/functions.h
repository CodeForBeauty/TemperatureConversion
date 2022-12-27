// make sure loads only once
#pragma once

// convert fahrenheit to celsius by using formula: C = 5/9*(F-32), where C - celsius degrees and F - fahrenheit degrees
float fahrenheit2celsius(float fahrenheit)
{
	return 5.0f / 9.0f * (fahrenheit - 32);
}

// convert celsius to fahrenheit by reversing previous formula: F = 5/9/C+32, where C - celsius degrees and F - fahrenheit degrees
float celsius2fahrenheit(float celsius)
{
	return celsius / (5.0f / 9.0f) + 32;
}