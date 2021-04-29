import datetime
from bs4 import BeautifulSoup
import urllib.request

print('  ○>> #오늘의 #국내 #코로나19 #현황 \n')
webpage = urllib.request.urlopen('http://ncov.mohw.go.kr/')
soup = BeautifulSoup(webpage, 'html.parser')
dayconfirm = soup.find('span',"data")
allinfo = soup.find('span', 'num')
print(' --> 국내발생 : ' , dayconfirm.get_text() , '\n --> 누적검사 : ', allinfo.get_text(),'\n\n')