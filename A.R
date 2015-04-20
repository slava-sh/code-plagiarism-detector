allData <- read.csv("output.tsv", sep="\t", header=TRUE)
data    <- data.frame(ans   = as.factor(allData$ans),
                      ratio = allData$dist_ratio,
                      size  = allData$mess_size)
rm(allData)
with(data, plot(ratio ~ size, col = ans))

classifier <- glm(ans ~ size + ratio, data=data, family=binomial)
slope      <- coef(classifier)[2]/(-coef(classifier)[3])
intercept  <- coef(classifier)[1]/(-coef(classifier)[3])
abline(intercept, slope)
