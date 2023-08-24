# FdF

This project is about creating a simple wireframemodel of a landscape.

---
# 使いかた

1. makeする
2. 生成された fdf を次のように使う
	./fdf "filename".fdf
	例: ./fdf test_maps/42.fdf

- .fdfのデータはすべての行の要素数が一致してないと無効なデータと見做されます
- trans_data.cのtrans_to_iso関数の -(point[i].z)に任意の値を掛けると高さ調整ができます。(0 ~ 1の範囲)
- このプロジェクトに含まれているminilibxはMac上でのみ機能します。linuxでは動きませんのでご注意を。