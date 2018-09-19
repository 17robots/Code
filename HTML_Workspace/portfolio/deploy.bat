npm run build

cd dist

git add -A
	
git commit -m 'deploy'

git push -f origin master

cd ..

