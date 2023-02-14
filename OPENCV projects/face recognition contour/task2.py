import cv2 as cv

    # funkcija cv.imread nuskaito jūsų nuotrauką, 1-spalvota foto
img = cv.imread('man.jpg', 1)
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    # žemiau pateikta funkcija išsaugo jūsų nuotraukos pilką variantą
    # pagal iškirptį, 0-nespalvota foto
white = cv.imread('man_cutted.jpg', 0)

    # Piešiama konturo atitiktis pagal foto
ret, im = cv.threshold(img_gray, 100, 225, cv.THRESH_BINARY_INV)
contours, hierarchy = cv.findContours(im, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
img = cv.drawContours(white, contours, -1, (0, 255, 75), 5)
    # išvesties pavadinimas
cv.imshow("Brychka golf 8", img)
    # publikavimas
print(img)

cv.waitKey(0)