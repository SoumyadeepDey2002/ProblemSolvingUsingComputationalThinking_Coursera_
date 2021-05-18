The code is in C++


Input Format -
input the following values with a space between each other or using enter

S - Susceptible people, people who don't have COVID yet in the area
I - Infected people in the area
R - Recovered people(usually 0 if the pandemic is about to start)
r0 - how many people can a infected person infect in 1 month
RecoverRate - The % of people who recover from covid in 1 month
MortalityRate - The % of people who die from covid in 1 month
V - amount of vaccines that can be given per month
maxbeds - max beds available for patients per month

You can also implement lockdowns by giving the value of n(no of months of lockdown)
then just give the month numbers that you want to implement lockdown

Output format -

column 1 = month number
column 2 = S
column 3 = I
column 4 = R that month
column 5 = deaths that month