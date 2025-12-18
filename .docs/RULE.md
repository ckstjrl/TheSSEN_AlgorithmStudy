# Study Rule (Git Workflow)

본 문서는 알고리즘 스터디를 위한 **단순하고 실무에 가까운 Git 협업 규칙**을 설명합니다.

---

## 1. 기본 원칙

* 중앙 레포: `ckstjrl/TheSSEN_AlgorithmStudy`
* 각자 **개인 브랜치(`user/<닉네임>`)에서만 작업**
* `main` 브랜치는 **관리자(ckstjrl)만 merge**
* **절대로 `main` 브랜치 조작 X**
* 결과 공유는 **Pull Request(PR)** 로 진행

---

## 2. 브랜치 전략

### 브랜치 구성

* `main` : 최종 공유 브랜치
* `user/ckstjrl`
* `user/cheoljun99`
* `user/KangJunBeom`
* `user/mindidii`
* `user/vestuni`

> 개인 브랜치는 최초 1회 생성 후 계속 사용합니다.

---

## 3. 디렉토리 / 파일 규칙

### BOJ

```
BOJ/BOJ1234/<닉네임>.cpp
```

### Programmers

```
PGS/PGS1234/<닉네임>.cpp
```

### 중요 규칙

* 문제 폴더는 여러 사람이 **같이 만들어도 충돌 없음**
* **파일명은 반드시 닉네임** (충돌 방지 핵심)
* 다른 사람 파일 수정 금지

---

## 4. 커밋 규칙

### 문제 풀이 커밋 메시지

```
solved(BOJ[문제번호] / 문제레벨): 문제이름
```

예시:

* `solved(BOJ1107 / G5): 리모컨`
* `solved(PGS42586 / Lv2): 기능개발`

---

## 5. 작업 순서 (팀원 기준)
### Step 0. config!!! (PC마다 1회)

```bash
git config --global user.name "본인 github 아이디"
git config --global user.email "본인 github 이메일"
```

### Step 1. 레포 클론 (최초 1회)

```bash
git clone https://github.com/ckstjrl/TheSSEN_AlgorithmStudy.git
cd TheSSEN_AlgorithmStudy
```

### Step 2. 개인 브랜치 생성 (최초 1회)

```bash
git switch -c user/<닉네임>
git push origin user/<닉네임>
```

### Step 3. 문제 풀이

* 예: `BOJ/BOJ1234/<닉네임>.cpp`
```bash
mkdir BOJ1234
cd BOJ1234
touch <닉네임>.cpp
```

### Step 4. 커밋

```bash
git add <닉네임>.cpp
git commit -m "solved(BOJ1234 / B3): 문제이름"
```

> ⚠️ commit하면서 **커밋명** 다시 확인 (오타 주의)

### Step 5. 푸시

```bash
git push origin user/<닉네임>
```

> ⚠️ push 전에 **커밋명** 또 다시 확인 (오타 주의)

### Step 6. Pull Request 생성 - 일주일에 한번 진행

* base: `main`
* compare: `user/<닉네임>`
* title : `<닉네임> / 월 주차`
* content : 
    ```
    <!-- ----- 여기부터 복사 ----- -->
    ---
    ## 🎈boj/pgs[문제번호] - 문제이름
    <br>

    #### 🗨 해결방법 :
    <br>


    #### 📝메모 : 
    <br>

    <!-- ----- 여기까지 복사 ----- -->
    ```

> ⚠️ PR 생성 전 `main` 최신화는 필수 아님

> ⚠️ merge 후 `main` 최신화 필수

### Step 7. merge 후 main 최신화
```bash
git switch main
git pull origin main
git switch user/<닉네임>
```
브랜치를 main으로 변경하고 pull받은 후 다시 본인 브랜치로 이동

> ⚠️ 꼭 최신화 후 본인 브랜치로 이동 -> 터미널에서 브랜치가 `(user/<닉네임>)`으로 이동했는지 꼭 확인

---

## 6. PR & Merge 규칙 (관리자)

* PR의 변경 파일 경로 확인
* 닉네임 파일만 수정되었는지 확인
* 이상 없으면 merge

> 같은 문제 폴더가 여러 PR에 있어도 충돌 없음

---

## 7. 충돌(Conflict) 관련 FAQ

### Q. 같은 문제 폴더를 여러 사람이 만들면 충돌 나나요?

A. ❌ 아닙니다. Git은 폴더가 아니라 **파일 경로 기준**으로 병합합니다.

### Q. 언제 충돌이 나나요?

* 같은 파일을 두 사람이 수정했을 때
* 폴더/파일을 이동·삭제했을 때

---

## 8. 최종 정리

* 팀원은 **개인 브랜치에서만 작업**
* PR만 올리고 `main`은 신경 쓰지 않음
* 머지는 관리자 `ckstjrl` 책임

이 규칙을 지키면 충돌 없이 안정적인 스터디 운영이 가능합니다.