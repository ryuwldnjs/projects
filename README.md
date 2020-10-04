# 용도
데스크탑이랑 노트북이랑 번갈아가면서 하는게 넘나 귀찮아서 만든 곳

현재는 시프(SP) 실습 과제 소스코드만

# push 사용법
git init
git add <파일이름> //모든 파일일경우 -A
git commit -m "커밋 설명메세지"
remote add origin http://github.com/ryuwldnjs/projects (레퍼지토리 주소)
git push -u origin master
:: 1,4번은 한번만 해주면 됨

# clone 사용법
git clone http://github.com/ryuwldnjs/projects

이럴경우 현재위치(pwd)에서 모든파일이 생성됨

# 오류 해결법
# [rejected]master -> master (fetch first) 에러
: 데이터손실을 우려하여 거부당한 것.
git push origin +master
강제로 진행해주면 된다.

# [rejected] master -> master(non-fast-forward)
Local에 있는 파일이 Github에 있는 파일보다 오래된 내용이기때문에 뜨는 것.
이 역시 데이터 증발을 방지

git pull origin masterd로 최신파일을 받아오고, 합쳐서 하면 됨
또는 
git push origin +master
강제로 진행주면 된다.
