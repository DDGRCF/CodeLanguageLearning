package main

import (
	"bytes"
	"fmt"
	"image"
	"io/ioutil"

	flag "github.com/spf13/pflag"
)

/* Python:
   hi, wi= image.shape
   hk, wk = kernel.shape
   image_padded = np.zeros(shape=(hi + hk - 1, wi + wk - 1))
   image_padded[hk//2:-hk//2, wk//2:-wk//2] = image
   out = np.zeros(shape=image.shape)
   for row in range(hi):
       for col in range(wi):
           for i in range(hk):
               for j in range(wk):
                   out[row, col] += image_padded[row + i, col + j]*kernel[i, j]
*/

func main() {
	var source = flag.StringP("source", "s", "./test.png", "source image")
	flag.Parse()

	var fread []byte
	var err error

	if fread, err = ioutil.ReadFile(*source); err != nil {
		panic(fmt.Sprintf("Reade %v fail! Error: %v", *source, err))
	}

	buffer := bytes.NewBuffer(fread)
	var img image.Image
	if img, _, err = image.Decode(buffer); err != nil {
		panic(fmt.Sprintf("Decode buffer fail! Error: %v", err))
	}

	kernel := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	newEmpty := image.NewNRGBA(
		image.Rectangle{image.Point{0, 0},
			image.Point{img.Bounds().Max.X + len(kernel) - 1, img.Bounds().Max.Y + len(kernel[0]) - 1}})

	for row := 0; row < len(kernel); row++ {
		for col := 0; col < len(kernel[0]); col++ {
			for i := 0; i < img.Bounds().Dy(); i++ {
				for j := 0; j < img.Bounds().Dx(); j++ {
				}
			}
		}
	}
	fmt.Println(newEmpty)

}
