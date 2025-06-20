#!/bin/bash

SERVER_BIN=./server
CLIENT_BIN=./client

# Mensajes de prueba
TESTS=(
    "Hola Mundo"
    ""
    "42 Málaga"
    "Mensaje con símbolos !@#\$%"
    "Mensaje con\nlíneas"
    "Mensaje muy largo....................................................................................."
)

echo "🔧 Compilando..."
make fclean && make > /dev/null
if [[ ! -f "$SERVER_BIN" || ! -f "$CLIENT_BIN" ]]; then
    echo "❌ Compilación fallida."
    exit 1
fi

echo "🚀 Lanzando servidor..."
$SERVER_BIN > server_output.txt &
SERVER_PID=$!
sleep 1

SERVER_PID_DISPLAY=$(head -n 1 server_output.txt | grep -o '[0-9]\+')

if [[ -z "$SERVER_PID_DISPLAY" ]]; then
    echo "❌ No se pudo obtener el PID del servidor."
    kill $SERVER_PID
    exit 1
fi

echo "✅ Server PID: $SERVER_PID_DISPLAY"
echo ""

ALL_PASS=true

for MESSAGE in "${TESTS[@]}"; do
    echo "📤 Enviando mensaje: \"$MESSAGE\""
    $CLIENT_BIN "$SERVER_PID_DISPLAY" "$MESSAGE"
    sleep 0.2

    OUTPUT=$(tail -n 1 server_output.txt)

    EXPECTED="=====${MESSAGE}====="

    if [[ "$OUTPUT" == "$EXPECTED" ]]; then
        echo "✅ OK: \"$OUTPUT\""
    else
        echo "❌ FAIL: \"$OUTPUT\""
        ALL_PASS=false
    fi
done

echo ""
echo "🧹 Limpiando..."
kill $SERVER_PID 2>/dev/null
rm -f server_output.txt

if [ "$ALL_PASS" = true ]; then
    echo "🎉 Todos los tests PASARON. Estás listo para Moulinette."
else
    echo "⚠️  Algunos tests FALLARON. Revisa tu output."
fi
