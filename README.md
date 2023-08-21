# FdF

This project is about creating a simple wireframemodel of a landscape.

---

# 使いかた

1. makeする
2. 生成された fdf を次のように使う
	./fdf "\<filename\>.fdf"

- .fdfのデータはすべての行で要素数が一致してないと無効なデータと見做されます
- trans_data.cのtrans_to_iso関数の -(point[i].z)に任意の値を掛けると高さ調整できます。
