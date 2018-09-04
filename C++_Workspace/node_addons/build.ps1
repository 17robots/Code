Write-Output "Building App..."

node-gyp rebuild

Write-Output "Built."

Write-Output

Write-Output "Relocating File"

Remove-Item ..\..\JavaScript_Workspace\node_addon_test\cash_drawer.node

Move-Item .\build\Release\cash_drawer.node ..\..\JavaScript_Workspace\node_addon_test\

Write-Output "File Relocated"