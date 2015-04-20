svg('plot.svg', width=4, height=3)

allData <- read.csv("output.tsv", sep="\t", header=TRUE)
data    <- data.frame(ratio = allData$dist_ratio,
                      dist  = allData$dist,
                      ans   = as.factor(allData$ans),
                      size  = allData$mess_size)
rm(allData)

with(data, plot(ratio ~ size, col=ans, pch=20, cex=0.4))

draw_simple_classifier <- function(y_small, x_threshold, y, col=0) {
    segments(0,           y_small, x_threshold,   y_small, col=col)
    segments(x_threshold, y_small, x_threshold,   y,       col=col)
    segments(x_threshold, y,       par("usr")[2], y,       col=col)
}

#MAX_DIST_RATIO       <- 0.37
#MAX_DIST_RATIO_SMALL <- 0.28
#SMALL_THRESHOLD      <- 440
#abline(v=SMALL_THRESHOLD, col=4)
#abline(MAX_DIST_RATIO_SMALL, 0, col=4)
#abline(MAX_DIST_RATIO, 0, col=4)

rect(400, 0.35/2, 410, 0.35, col="lightpink", border=NA)

#MAX_DIST_RATIO       <- 0.35
#MAX_DIST_RATIO_SMALL <- MAX_DIST_RATIO / 2
#SMALL_THRESHOLD      <- 400
#draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col=8)

#MAX_DIST_RATIO       <- 0.35
#MAX_DIST_RATIO_SMALL <- 0.2
#SMALL_THRESHOLD      <- 400
#draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col=8)

#abline(0.228, 0)
#abline(0.1029922568,  0.0003120542);

MAX_DIST_RATIO       <- 0.35
MAX_DIST_RATIO_SMALL <- 0.228
SMALL_THRESHOLD      <- 450
draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col="red")

dev.off()
