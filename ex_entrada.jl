function sum(a::Int32, b::Int32)::Int32
   return a+b
end
function mean(a::Float32, b::Float32)::Float32
   return (a+b)/2
end
m = 2
k = sum(5, m) * 5
matrix = [1 4;2 5;3 5]
matrix[m,m]
vector = [1; 4; 3]
vector[1]
x = 17.0
z = x + mean(x-7, vector[1]*2)
