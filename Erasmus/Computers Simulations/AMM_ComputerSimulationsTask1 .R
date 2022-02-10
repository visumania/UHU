#Exercise 1

realPI = 3.14159265
List <- vector()

for (i in 1:10000)
{
  runs <- i
  xs <- runif(runs,min = -0.5,max = 0.5)
  ys <- runif(runs,min = -0.5,max = 0.5)
  in.circle <- xs^2 + ys^2 <= 0.5^2
  mc.pi <- (sum(in.circle)/runs)*4
  List <- c(List,abs(realPI-mc.pi))
}

plot(List,type="l",xlab="Sample size",ylab="Approximation error")

#Exercise 2

runs <- 100000
xs <- runif(runs,min = 0,max = 8)
ys <- runif(runs,min = 0,max = 2)
in.figure <- (xs<=2 & ys<=xs) | (xs>2 & xs<=6 & ys<=(-1/4)*xs+(5/2)) | (xs>6 & ys<=(-1/2)*xs+4)
mc.area <- (sum(in.figure)/runs)*16 
plot(xs,ys,pch='.',col=ifelse(in.figure,"blue","grey"),xlab = '',ylab = '',asp = 1,main = paste("MC Approximation of area = ",mc.area))