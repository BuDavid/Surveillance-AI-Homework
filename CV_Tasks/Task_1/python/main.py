import cv2

def main():
    image = cv2.imread("../resources/test.png")

    if image is None:
        print("Error: couldn't open image")
        exit()

    image = cv2.resize(image, (500, 500))

    image = cv2.flip(image, -1)

    image = image[0:400, 0:400]

    height, width = image.shape[:2]

    rotate_matrix_45 = cv2.getRotationMatrix2D((width / 2, height / 2), 45.0, 1.0)
    image = cv2.warpAffine(image, rotate_matrix_45, (width, height))

    cv2.imshow("changed image", image)
    cv2.imwrite("new.png", image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()

