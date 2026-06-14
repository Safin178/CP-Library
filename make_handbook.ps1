Remove-Item CP-Library-Handbook.cpp -ErrorAction Ignore

$exclude = @(
    "test.cpp"
)

Get-ChildItem -Recurse -Filter *.cpp |
Where-Object { 
    $_.FullName -notmatch "\\.cph\\" -and
    $_.Name -notin $exclude
} |
ForEach-Object {

    $folder = $_.Directory.Name
    $name = $_.BaseName

    @"

// ==================================================
// $folder
// ==================================================


// ---------------- $name ----------------

"@ | Out-File CP-Library-Handbook.cpp -Append

    Get-Content $_.FullName | Out-File CP-Library-Handbook.cpp -Append

    "`n`n" | Out-File CP-Library-Handbook.cpp -Append
}

Write-Host "Done! CP-Library-Handbook.cpp created"