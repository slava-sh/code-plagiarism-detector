draw_simple_classifier <- function(y_small, x_threshold, y, col=8) {
    segments(0,           y_small, x_threshold,   y_small, col=col)
    segments(x_threshold, y_small, x_threshold,   y,       col=col)
    segments(x_threshold, y,       par("usr")[2], y,       col=col)
}

args       <- commandArgs(trailingOnly=TRUE)
input.tsv  <- args[1]
output.svg <- args[2]

data       <- read.csv(input.tsv, sep="\t", header=TRUE)
data$Ans   <- as.factor(data$Ans)
data$Guess <- as.factor(data$Guess)
data$Right <- data$Ans == data$Guess

size <- 12
svg(output.svg, width=size, height=size)

with(data, plot(DistRatio ~ Size,
                col=ifelse(Right, ifelse(Guess == 0, 8, "lightpink"), ifelse(Guess == 0, "blue", "red")),
                cex=ifelse(Right, 0.3, 0.6),
                pch=16))

if (size >= 20) {
    with(data[!data$Right & data$Ans == 0,], text(DistRatio ~ Size, labels=paste(I, J), cex=0.8, pos=4))
}

MAX_DIST_RATIO       <- 0.35
MAX_DIST_RATIO_SMALL <- 0.228
SMALL_THRESHOLD      <- 450
draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col="red")

x <- c(1:2000)
HI <- 0.35
LO <- 0.228
y <- LO + (HI - LO) / (1 + exp(-0.03 * (x - 580)))
points(x, y, cex=0.1)

invisible(dev.off())
